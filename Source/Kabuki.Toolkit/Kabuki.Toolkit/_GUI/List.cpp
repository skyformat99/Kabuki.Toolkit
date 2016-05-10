/****************************************************************************
  
  GLUI User Interface Toolkit
  ---------------------------

     list.cpp - List control class


          --------------------------------------------------

  Copyright (c) 2004 John Kew

  This software is provided 'as-is', without any express or implied 
  warranty. In no event will the authors be held liable for any damages 
  arising from the use of this software. 

  Permission is granted to anyone to use this software for any purpose, 
  including commercial applications, and to alter it and redistribute it 
  freely, subject to the following restrictions: 

  1. The origin of this software must not be misrepresented; you must not 
  claim that you wrote the original software. If you use this software 
  in a product, an acknowledgment in the product documentation would be 
  appreciated but is not required. 
  2. Altered source versions must be plainly marked as such, and must not be 
  misrepresented as being the original software. 
  3. This notice may not be removed or altered from any source distribution. 

*****************************************************************************/

#include "internal_control.h"
#include <cmath>
#include <sys/timeb.h>

/****************************** List::List () **********/

List::List (Node *parent, bool scroll,
                      int id, CB callback
                      /*,Control *object 
                      InterObject_CB obj_cb*/)
{
  common_construct (parent, NULL, scroll, id, callback/*, object, obj_cb*/);
}

/****************************** List::List () **********/

List::List (Node *parent,
                      String& live_var, bool scroll, 
                      int id, 
                      CB callback 
                      /* ,Control *object
                      ,InterObject_CB obj_cb*/)
{
  common_construct (parent, &live_var, scroll, id, callback/*, object, obj_cb*/);
}

/****************************** List::common_construct () **********/

void List::common_construct (
  Node *parent,
  String* data, bool scroll, 
  int id, 
  CB callback
  /*,Control *object
  , InterObject_CB obj_cb*/)
{
  common_init ();
  Node *listPanel = parent;

  if (scroll) {
    Panel *p = new Panel (parent,"",PANEL_NONE);
    p->x_off = 1;
    listPanel = p;
  }
  this->ptr_val     = data;
  if (data) {
    this->live_type = LIVE_STRING;
  }
  this->user_id     = id;
  this->callback    = callback;
  this->name        = "list";
  listPanel->add_control (this);
  if (scroll) 
  {
    new Column (listPanel, false);
    scrollbar = 
      new Scrollbar (listPanel,
                         "scrollbar",
                         SCROLL_VERTICAL,
                         SCROLL_INT);
    scrollbar->set_object_callback (List::scrollbar_callback, this);
    scrollbar->set_alignment (ALIGN_LEFT);
    // scrollbar->can_activate = false; //kills ability to mouse drag too
  }
  init_live ();
}

/****************************** List::mouse_down_handler () **********/
int    List::mouse_down_handler (int local_x, int local_y)
{
  int tmp_line;
  unsigned long int ms;
  timeb time;
  ftime (&time);
  ms = time.millitm + (time.time)*1000;

  tmp_line = find_line (local_x-x_abs, local_y-y_abs-5);  
  if (tmp_line == -1) {
    if (glui)
      glui->deactivate_current_control ();
    return false;
  }

  if (tmp_line < num_lines) {
    curr_line = tmp_line;
    if (scrollbar)
      scrollbar->set_int_val (curr_line);
    this->execute_callback ();
    if (associated_object != NULL)
      if (cb_click_type == SINGLE_CLICK) {
        if (obj_cb) {
          // obj_cb (associated_object, user_id);
          obj_cb (this);
        }
      } else {
        if (last_line == curr_line && (ms - last_click_time) < 300) {
          //obj_cb (associated_object, user_id);
          obj_cb (this);
        } else {
          last_click_time = ms;
          last_line = curr_line;
        }
      }
    if (can_draw ())
      update_and_draw_text ();
  }

  return true;
}




/******************************** List::mouse_up_handler () **********/

int    List::mouse_up_handler (int local_x, int local_y, bool inside)
{
  return false;
}


/***************************** List::mouse_held_down_handler () ******/

int    List::mouse_held_down_handler (int local_x, int local_y,
                           bool new_inside)
{
  return false;
}


/****************************** List::key_handler () **********/

int    List::key_handler (unsigned char key,int modifiers)
{


  draw_text_only = false;  /** Well, hack is not yet working **/
  update_and_draw_text ();
  draw_text_only = false;

  return true;
}


/****************************** List::activate () **********/

void    List::activate (int how)
{
//   if (debug)
//     dump (stdout, "-> ACTIVATE");
  active = true;

  if (how == ACTIVATE_MOUSE)
    return;  /* Don't select everything if activated with mouse */

}


/****************************** List::deactivate () **********/

void    List::deactivate (void)
{
  active = false;
  redraw ();
}

/****************************** List::Draw () **********/

void    List::Draw (int x, int y)
{
  int line = 0;
  int box_width;
  List_Item *item;
 
  DRAWINGSENTINAL_IDIOM

  /* Bevelled Border */
  glBegin (GL_LINES);
  glColor3f (.5, .5, .5);
  glVertex2i (0, 0);     glVertex2i (w, 0);
  glVertex2i (0, 0);     glVertex2i (0, h);     

  glColor3f (1., 1., 1.);
  glVertex2i (0, h);     glVertex2i (w, h);
  glVertex2i (w, h);     glVertex2i (w, 0);

  if (enabled)
    glColor3f (0., 0., 0.);
  else
    glColor3f (.25, .25, .25);
  glVertex2i (1, 1);     glVertex2i (w-1, 1);
  glVertex2i (1, 1);     glVertex2i (1, h-1);

  glColor3f (.75, .75, .75);
  glVertex2i (1, h-1);     glVertex2i (w-1, h-1);
  glVertex2i (w-1, h-1);   glVertex2i (w-1, 1);
  glEnd ();

  /* Draw Background if enabled*/
  if (enabled) {
    glColor3f (1., 1., 1.);
    glDisable (GL_CULL_FACE);
    glBegin (GL_QUADS);
    glVertex2i (2, 2);     glVertex2i (w-2, 2);
    glVertex2i (w-2, h-2);               glVertex2i (2, h-2);
    glEnd ();
  } else {
    glColor3f (.8, .8, .8);
    glDisable (GL_CULL_FACE);
    glBegin (GL_QUADS);
    glVertex2i (2, 2);     glVertex2i (w-2, 2);
    glVertex2i (w-2, h-2);               glVertex2i (2, h-2);
    glEnd ();
  }

  /* Figure out how wide the box is */
  box_width = get_box_width ();

  /* Figure out which lines are visible*/

  visible_lines = (int) (h-20)/15;

  item = (List_Item *) items_list.first_child ();

  line = 0;
  while (item) {
    if (line < start_line) {
      line++;
      item = (List_Item *) item->next ();
      continue;
    }
    if (line >= start_line && line <= (start_line+visible_lines)) {
      if (curr_line == line)
	draw_text (item->text.c_str (),1,0, (line - start_line)*15);
      else
	draw_text (item->text.c_str (),0,0, (line - start_line)*15);
    }
    line++;
    item = (List_Item *) item->next ();
  }

  if (scrollbar) {
    scrollbar->set_int_limits (MAX (0,num_lines-visible_lines), 0);
    glPushMatrix ();
    glTranslatef (scrollbar->x_abs-x_abs, scrollbar->y_abs-y_abs,0.0);
    scrollbar->draw_scroll ();
    glPopMatrix ();
  }
}

/********************************* List::draw_text () ****************/

void    List::draw_text (const char *t, int selected, int x, int y)
{
  int text_x, i, x_pos;
  int box_width;

  DRAWINGSENTINAL_IDIOM

  /** Find where to Draw the text **/

  text_x = 2 + LIST_BOXINNERMARGINX;

  /** Draw selection area dark **/
  if (enabled && selected) {
    glColor3f (0.0f, 0.0f, .6f);
    glBegin (GL_QUADS);
    glVertex2i (text_x, y+5);    glVertex2i (w-text_x, y+5);
    glVertex2i (w-text_x, y+19);    glVertex2i (text_x, y+19);
    glEnd ();
  }
  box_width = get_box_width ();   

  if (!selected || !enabled) {   /* No current selection */
    x_pos = text_x;                /*  or control disabled */
    if (enabled)
      glColor3b (0, 0, 0);
    else
      glColor3b (32, 32, 32);
    
    glRasterPos2i (text_x, y+15);
    i = 0;
    while (t[i] != '\0' && substring_width (t,0,i) < box_width) {
      glutBitmapCharacter (get_font (), t[i]);
      x_pos += char_width (t[i]);
      i++;
    }
  }
  else { /* There is a selection */
    i = 0;
    x_pos = text_x;
    glColor3f (1., 1., 1.);
    glRasterPos2i (text_x, y+15);
    while (t[i] != '\0' && substring_width (t,0,i) < box_width) {
      glutBitmapCharacter (get_font (), t[i]);
      x_pos += char_width (t[i]);
      i++;
    }
  }
}


int List::find_line (int x, int y) {
  return start_line + ((int) (y/15));
}

int      List::get_box_width () {
   return MAX (this->w 
		   - 6     /*  2 * the two-line box border */ 
		   - 2 * LIST_BOXINNERMARGINX, 0);

}

/******************************** List::substring_width () *********/
int  List::substring_width (const char *t, int start, int end)
{
  int i, width;

  width = 0;

  for (i=start; i<=end; i++)
    width += char_width (t[i]); 

  return width;
}
 

/***************************** List::update_and_draw_text () ********/

void   List::update_and_draw_text (void)
{
  if (NOT can_draw ())
    return;

  //update_substring_bounds ();
  /*  printf ("ss: %d/%d\n", substring_start, substring_end);                  */

  redraw ();
}


/********************************* List::special_handler () **********/

int    List::special_handler (int key,int modifiers)
{
  if (NOT glui)
    return false;

  if (key == GLUT_KEY_DOWN) {
     if (curr_line < num_lines) {
       curr_line++;
       if (curr_line > start_line+visible_lines)
	 start_line++;
     }
  } else if (key == GLUT_KEY_UP) {
     if (curr_line > 0) {
       curr_line--;
       if (curr_line < start_line)
	 start_line--;
     }
  }

  if (scrollbar)
    scrollbar->set_int_val (curr_line);
  redraw ();
  return true;
}


/************************************ List::update_size () **********/

void   List::update_size (void)
{
  if (NOT glui)
    return;

  if (w < LIST_MIN_TEXT_WIDTH)
      w = LIST_MIN_TEXT_WIDTH;
}

/**************************************** Listbox::Add_item () **********/

int  List::Add_item (int id, const char *new_text)
{
  List_Item *new_node = new List_Item;
  List_Item *head;

  new_node->text = new_text;
  new_node->id = id;

  head = (List_Item*) items_list.first_child ();
  new_node->link_this_To_parent_last (&items_list);

  if (head == NULL) {
    /***   This is first item added   ***/

    int_val       = id+1;  /** Different than id **/
    //    do_selection (id);
    last_live_int = id;

    if (glui)
      glui->post_update_main_gfx ();
  }
  num_lines++;
  if (scrollbar)
    scrollbar->set_int_limits (MAX (num_lines-visible_lines,0), 0);

  return true;
}

/************************************** Listbox::delete_ () **********/

int  List::delete_all ()
{
  List_Item *item;

  item = (List_Item *) items_list.first_child ();
  while (item) {
    item->unlink ();
    delete item;
    item = (List_Item *) items_list.first_child ();
  }

  num_lines = 0;
  curr_line = 0;

  return true;
}


/************************************** Listbox::delete_item () **********/

int  List::delete_item (const char *text)
{
  List_Item *node = get_item_ptr (text);

  if (node) {
    node->unlink ();
    delete node;
    num_lines--;
    return true;
  }
  else {
    return false;
  }
}


/************************************** Listbox::delete_item () **********/

int  List::delete_item (int id)
{
  List_Item *node = get_item_ptr (id);

  if (node) {
    node->unlink ();
    delete node;
    num_lines--;
    return true;
  }
  else {
    return false;
  }
}


/************************************ Listbox::get_item_ptr () **********/

List_Item *List::get_item_ptr (const char *text)
{
  List_Item *item;

  item = (List_Item *) items_list.first_child ();
  while (item) {
    if (item->text == text)
      return item;
    
    item = (List_Item *) item->next ();
  }

  return NULL;
}


/************************************ Listbox::get_item_ptr () **********/

List_Item *List::get_item_ptr (int id)
{
  List_Item *item;

  item = (List_Item *) items_list.first_child ();
  while (item) {
    if (item->id == id)
      return item;
    
    item = (List_Item *) item->next ();
  }

  return NULL;
}

/**************************************** List::mouse_over () ********/

int    List::mouse_over (int state, int x, int y)
{
  glutSetCursor (GLUT_CURSOR_LEFT_ARROW);

  return true;
}

void List::scrollbar_callback (Control *my_scrollbar) {
  Scrollbar *sb = dynamic_cast<Scrollbar*> (my_scrollbar);
  if (!sb) return;
  List* me = (List*) sb->associated_object;
  if (me->scrollbar == NULL)
    return;
  int new_start_line = sb->get_int_val (); // TODO!!
  me->start_line = new_start_line;

  if (me->can_draw ())
    me->update_and_draw_text ();
}
