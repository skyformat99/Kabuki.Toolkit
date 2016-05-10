/****************************************************************************
  
  GLUI User Interface Toolkit
  ---------------------------

     control.cpp - top-level Control class


          --------------------------------------------------

  Copyright (c) 1998 Paul Rademacher

  WWW:    http://sourceforge.net/projects/glui/
  Forums: http://sourceforge.net/forum/?group_id=92496

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

int _draw_border_only = 0;

/*************************** Drawing Utility routines *********************/

/* Redraw this control. */
void	      Control::redraw (void) {
    if (glui==NULL || hidden) return;
    if (glui->should_redraw_now (this))
      translate_and_draw_front ();
}

/** Redraw everybody in our window. */
void	     Control::redraw_window (void) {
  if (glui==NULL || hidden) return;
  if (glui->get_glut_window_id () == -1) return;
  int orig = set_To_glut_window ();
  glutPostRedisplay ();
  restore_window (orig);
}



/* Control::translate_and_draw_front () ********/

void Control::translate_and_draw_front ()
{
  DRAWINGSENTINAL_IDIOM

  glMatrixMode (GL_MODELVIEW);
  glPushMatrix ();
  translate_To_origin ();
  Draw (0,0);
  glPopMatrix ();
}


/********** Control::set_To_bkgd_color () ********/

void Control::set_To_bkgd_color (void)
{
  if (NOT glui)
    return;

  glColor3ubv (glui->bkgd_color);
}

/******** Control::draw_box_inwards_outline () ********/

void Control::draw_box_inwards_outline (int x_min, int x_max, int y_min, int y_max)
{
  glBegin (GL_LINES);
  glColor3f (.5, .5, .5);
  glVertex2i (x_min, y_min);     glVertex2i (x_max, y_min);
  glVertex2i (x_min, y_min);     glVertex2i (x_min, y_max);     

  glColor3f (1., 1., 1.);
  glVertex2i (x_min, y_max);     glVertex2i (x_max, y_max);
  glVertex2i (x_max, y_max);     glVertex2i (x_max, y_min);

  if (enabled)
    glColor3f (0., 0., 0.);
  else
    glColor3f (.25, .25, .25);

  glVertex2i (x_min+1, y_min+1);     glVertex2i (x_max-1, y_min+1);
  glVertex2i (x_min+1, y_min+1);     glVertex2i (x_min+1, y_max-1);

  glColor3f (.75, .75, .75);
  glVertex2i (x_min+1, y_max-1);     glVertex2i (x_max-1, y_max-1);
  glVertex2i (x_max-1, y_max-1);     glVertex2i (x_max-1, y_min+1);
  glEnd ();  
}


/******* Control::draw_box () **********/

void Control::draw_box (int x_min, int x_max, int y_min, int y_max, float r, float g, float b)
{
  if (r == 1.0 AND g == 1.0 AND b == 1.0 AND NOT enabled AND glui) {
    draw_bkgd_box (x_min, x_max, y_min, y_max);
    return;
  }

  glColor3f (r, g, b);
  glBegin (GL_QUADS);
  glVertex2i (x_min, y_min);       glVertex2i (x_max, y_min);
  glVertex2i (x_max, y_max);       glVertex2i (x_min, y_max);
  glEnd ();
}


/******* Control::draw_bkgd_box () **********/

void Control::draw_bkgd_box (int x_min, int x_max, int y_min, int y_max)
{
  set_To_bkgd_color ();

  glBegin (GL_QUADS);
  glVertex2i (x_min, y_min);       glVertex2i (x_max, y_min);
  glVertex2i (x_max, y_max);       glVertex2i (x_min, y_max);
  glEnd ();
}


/**** Control::draw_active_area () ********/

void Control::draw_active_box (int x_min, int x_max, int y_min, int y_max)
{
  DRAWINGSENTINAL_IDIOM

  if (active) {
    glEnable (GL_LINE_STIPPLE);
    glLineStipple (1, 0x5555);
    glColor3f (0., 0., 0.);
  } else {
    set_To_bkgd_color ();
  }

  glBegin (GL_LINE_LOOP);
  glVertex2i (x_min, y_min);      glVertex2i (x_max, y_min);
  glVertex2i (x_max, y_max);      glVertex2i (x_min, y_max);
  glEnd ();
  
  glDisable (GL_LINE_STIPPLE);
}


/**** Control::draw_emboss_box () ********/

void   Control::draw_emboss_box (int x_min,int x_max,int y_min,int y_max)
{
  glLineWidth (1.0);
  glColor3f (1.0, 1.0, 1.0);

  glBegin (GL_LINE_LOOP);
  glVertex2i (x_min, y_min);    glVertex2i (x_max, y_min);
  glVertex2i (x_max, y_max);    glVertex2i (x_min, y_max);
  glEnd ();
 
  glBegin (GL_LINE_LOOP);
  glVertex2i (x_min+1, y_min+1);    glVertex2i (x_max-1, y_min+1);
  glVertex2i (x_max-1, y_max-1);    glVertex2i (x_min+1, y_max-1);
  glEnd ();
  
  glColor3f (.5, .5, .5);
  glBegin (GL_LINE_LOOP);
  glVertex2i (x_min, y_min);
  glVertex2i (x_max-1, y_min);
  glVertex2i (x_max-1, y_max-1);
  glVertex2i (x_min, y_max-1);
  glEnd ();
}



/******* GLUT_Control::draw_recursive () **********/

void Control::draw_recursive (int x, int y)
{
  Control *node;

  /*  printf ("%s %d\n", this->name.c_str (), this->hidden);*/
  if (NOT can_draw ())
    return;

  /*if (1) {  --  Debugging to check control width  
    glColor3f (1.0, 0.0, 0.0);
    glBegin (GL_LINES);
    glVertex2i (x_abs, y_abs);00
    glVertex2i (x_abs+w, y_abs);

    glEnd ();
    }*/

  glMatrixMode (GL_MODELVIEW);
  glPushMatrix ();

  glTranslatef ((float) this->x_abs + .5, 
		 (float) this->y_abs + .5, 
		0.0);

  if (NOT _draw_border_only) {
    if (NOT strcmp (name.c_str (), "Rollout")) {
    }

    this->Draw (this->x_off, this->y_off_Top);
  } 
  else 
  {
    if (dynamic_cast<Column*> (this)) {
      /*   printf ("%s w/h:   %d/%d\n", (char*) name, w, h);              */
      /*w = 2;              */
    }

    /* The following draws the area of each control              */
    glColor3f (1.0, 0.0, 0.0);
    glBegin (GL_LINE_LOOP);
    glVertex2i (0, 0); glVertex2i (w, 0);
    glVertex2i (w, h); glVertex2i (0, h);
    glEnd ();
  }
  glPopMatrix ();
  
  node = (Control*) first_child ();
  while (node) {
    node->draw_recursive (node->x_abs, node->y_abs);
    node = (Control*) node->next ();
  }
}


/****** Control::set_To_glut_window () *********/
/*  Sets the current window to the glut window associated with this control  */

int Control::set_To_glut_window ()
{
  int orig_window;

  if (NOT glui) 
    return 1;

  orig_window = glutGetWindow ();

  glutSetWindow (glui->get_glut_window_id ());

  return orig_window;
}


/********** Control::restore_window () *********/

void Control::restore_window (int orig)
{
  if (orig > 0)
    glutSetWindow (orig);
}



/****************************** Text ***************************/

/*************** Control::set_font () **********/

void Control::set_font (void *new_font)
{
  font = new_font;
  redraw ();
}


/********** Control::draw_string () ************/

void Control::draw_string (const char *text)
{
  _glutBitmapString (get_font (), text);
}


/**************** Control::draw_char () ********/

void Control::draw_char (char c)
{
  glutBitmapCharacter (get_font (), c);
}


/*********** Control::string_width () **********/

int Control::string_width (const char *text)
{
  return _glutBitmapWidthString (get_font (), text);
}


/************* Control::char_width () **********/

int Control::char_width (char c)
{ /* Hash table for faster character width lookups - JVK 
       Speeds up the textbox a little bit.
  */
  int hash_index = c % CHAR_WIDTH_HASH_SIZE;
  if (char_widths[hash_index][0] != c) {
    char_widths[hash_index][0] = c;
    char_widths[hash_index][1] = glutBitmapWidth (get_font (), c);
  }
  return char_widths[hash_index][1];
}


/*************** Control::get_font () **********/

void *Control::get_font (void)
{
  /*** Does this control have its own font? ***/
  if (this->font != NULL)
    return this->font;
  
  /*** Does the parent glui have a font? ***/
  if (glui)
    return glui->font;

  /*** Return the default font ***/
  return GLUT_BITMAP_HELVETICA_12;
}


/************* Control::draw_name () ***********/
/* This draws the name of the control as either black (if enabled), or       */
/* embossed if disabled.                                                     */

void Control::draw_name (int x, int y)
{
  if (NOT can_draw ())
    return;

  if (enabled)
  {
    set_To_bkgd_color ();
    glRasterPos2i (x+1, y+1);
    draw_string (name);
    glColor3b (0, 0, 0);
    glRasterPos2i (x, y);
    draw_string (name);
  }
  else
  {   /* Control is disabled - emboss the string */
    glColor3f (1.0f, 1.0f, 1.0f);
    glRasterPos2i (x+1, y+1);
    draw_string (name);
    glColor3f (.4f, .4f, .4f);
    glRasterPos2i (x, y);
    draw_string (name);
  }
}


/**************************** Layout and Packing *********************/

/****** Control::align () **************/

void Control::align ()
{
  int  col_x, col_y, col_w, col_h, col_x_off, col_y_off;
  int  orig_x_abs;

  orig_x_abs = x_abs;

  /* Fix alignment bug relating to columns              */
  /*return;              */

  if (NOT parent ())
    return;  /* Clearly this shouldn't happen, though */

  get_this_column_dims (&col_x, &col_y, &col_w, &col_h, 
		       &col_x_off, &col_y_off);

  if (dynamic_cast<Column*> (this)) {
    /*		if (this->prev () != NULL) {
		 ((Control*)prev ())->get_this_column_dims (&col_x, &col_y, &col_w, &col_h, 
		&col_x_off, &col_y_off);
		
		x_abs = col_x + col_w;
		}
		else {
		x_abs = ((Control*)parent ())->x_abs;
		}
		*/
    return;
  }

  if (alignment == ALIGN_LEFT) {
    x_abs = col_x + col_x_off;
  }
  else if (alignment == ALIGN_RIGHT) {
    x_abs = col_x + col_w - col_x_off - this->w;
  }
  else if (alignment == ALIGN_CENTER) {
    x_abs = col_x + (col_w - this->w) / 2;
  }

  if (this->is_container) {
    /***   Shift all child columns   ***/
    int delta = x_abs - orig_x_abs;

    Control *node;
		
    node = (Control*) this->first_child ();
    while (node != NULL) {
      if (dynamic_cast<Column*> (node)) { 
	node->x_abs += delta;
      } 

      node = (Control*) node->next ();
    }
  }

}


/************** Control::pack () ************/
/* Recalculate positions and offsets  */

void Control::pack_old (int x, int y)
{
  Control  *node;
  int            max_w, curr_y, curr_x, max_y;
  int            x_in = x, y_in =y;
  int            x_margin, y_margin_Top, y_margin_bot;
  int            y_Top_column;
  int            column_x;
  Column   *curr_column = NULL;
  this->update_size ();
  x_margin     = this->x_off;
  y_margin_Top = this->y_off_Top;
  y_margin_bot = this->y_off_bot;
  this->x_abs = x_in;
  this->y_abs = y_in;
  max_w  = -1;
  max_y  = -1;
  curr_x = this->x_abs + x_margin;
  curr_y = this->y_abs + y_margin_Top;
  /*** Record start of this set of columns ***/
  y_Top_column = curr_y;
  column_x     = 0;
  if (this == glui->mainPanel) {
    x=x;
  }
  /*** Iterate over children, packing them first ***/
  node = (Control*) this->first_child ();
  while (node != NULL) {
    if (dynamic_cast<Panel*> (node) && !node->collapsible) { 
      /* Pad some space above fixed size panels */
      curr_y += ITEMSPACING;
    } 
    else if (dynamic_cast<Column*> (node)) {
      curr_column = (Column*) node;
      if (1) {
	column_x += max_w + 2 * x_margin;
	curr_x  += max_w + 2 * x_margin;
      }
      else {
	column_x += max_w + 0 * x_margin;
	curr_x  += max_w + 0 * x_margin;
      }
      /*node->pack (curr_x, curr_y);              */
      node->x_abs = curr_x;
      node->y_abs = y_Top_column;
      node->w     = 2;
      node->h     = curr_y - y_Top_column;
      curr_x  += x_margin * 3 + 40;
      curr_y  = y_Top_column;
      max_w = 0;
      node = (Control*) node->next ();
      continue;
    }
    node->pack (curr_x, curr_y);
    if (dynamic_cast<Panel*> (node) && !node->collapsible)  
      /* Pad some space below fixed size panels */
      curr_y += ITEMSPACING;
    curr_y  += node->h;
    if (node->w > max_w) {
      max_w = node->w;
      if (curr_column != NULL)
	curr_column->w = max_w;
    }
    node = (Control*) node->next ();
    if (node) {
      curr_y += ITEMSPACING;
    }
    if (curr_y > max_y)
      max_y = curr_y;
  }
  if (this->is_container) {
    max_y += y_margin_bot;  /*** Add bottom border inside box */
    if (this->first_child ()) {
      if (dynamic_cast<Rollout*> (this)) {	
	/**  We don't want the rollout to shrink in width when it's
	  closed **/
	this->w = MAX (this->w, column_x + max_w + 2 * x_margin);
      }
      else {
	this->w        = column_x + max_w + 2 * x_margin;
      }
      this->h        = (max_y - y_in);
    }
    else  {            /* An empty container, so just assign default w & h */
      this->w        = DEFAULT_CONTROL_WIDTH;
      this->h        = DEFAULT_CONTROL_HEIGHT;
    }
    /** Expand panel if necessary (e.g., to include all the text in 
      a panel label) **/
    this->update_size ();   
  }
}

/*** Control::get_this_column_dims () **********/
/* Gets the x,y,w,h,and x/y offsets of the column to which a control belongs */

void    Control::get_this_column_dims (int *col_x, int *col_y, 
					    int *col_w, int *col_h, 
					    int *col_x_off, int *col_y_off)
{
  Control *node, *parent_ptr;
  int           parent_h, parent_y_abs;

  parent_ptr = (Control*) parent ();

  if (parent_ptr==NULL)
    return;

  parent_h     = parent_ptr->h;
  parent_y_abs = parent_ptr->y_abs;
  
  if (dynamic_cast<Panel*> (parent_ptr) AND
       parent_ptr->int_val == PANEL_EMBOSSED AND
       parent_ptr->name != "") {
    parent_h -= PANEL_EMBOSS_TOP;
    parent_y_abs += PANEL_EMBOSS_TOP;
  }

  if (0) {
    Node *first, *last, *curr;

    /**   Look for first control in this column   **/
    first = this;
    while (first->prev () AND !dynamic_cast<Column*> (first->prev ())) 
      first = first->prev ();

    /**   Look for last control in this column    **/
    last = this;
    while (last->next () AND !dynamic_cast<Column*> (first->next ()))
      last = last->next ();

    curr = first;
    int max_w = -1;
    do {
      if (((Control*)curr)->w > max_w)
	max_w = ((Control*)curr)->w;

      if (curr == last)
	break;

      curr = curr->next ();
    } while (curr != NULL);

    *col_x     = ((Control*)first)->x_abs;
    *col_y     = ((Control*)first)->y_abs;
    *col_w     = max_w;
    if (parent ()) {
      *col_h     = ((Control*)parent ())->h;
      *col_x_off = ((Control*)parent ())->x_off;
    }
    else {
      *col_h = 10;
      *col_x_off = 0;
    }
    *col_y_off = 0;

    return;
  }

  if (1) {    /* IS THIS WRONG? */
    /*** Look for preceding column ***/
    node = (Control*) this->prev ();
    while (node) {
      if (dynamic_cast<Column*> (node)) {
	*col_x     = node->x_abs;
	*col_y     = parent_y_abs;
	*col_w     = node->w;
	*col_h     = parent_h;
	*col_x_off = node->x_off;
	*col_y_off = 0;

	return;
      }

      node = (Control*) node->prev ();
    }

    /*** Nope, Look for next column ***/
    node = (Control*) this->next ();
    while (node) {
      if (dynamic_cast<Column*> (node)) {
	*col_x     = parent_ptr->x_abs;
	*col_y     = parent_y_abs;
	*col_w     = node->x_abs - parent_ptr->x_abs;
	*col_h     = parent_h;
	*col_x_off = node->x_off;
	*col_y_off = 0;

	return;
      }

      node = (Control*) node->next ();
    }

    /***   This is single-column panel, so return panel dims   ***/
    *col_x     = parent_ptr->x_abs;
    *col_y     = parent_y_abs;
    *col_w     = parent_ptr->w;
    *col_h     = parent_h;
    *col_x_off = parent_ptr->x_off;
    *col_y_off = 0;
  }
}


void    Control::pack (int x, int y)
{
  Control  *node;
  int            max_w, curr_y, curr_x, max_y;
  int            x_in = x, y_in =y;
  int            x_margin, y_margin_Top, y_margin_bot;
  int            y_Top_column;
  int            column_x;
  Column   *curr_column = NULL;

  this->update_size ();

  x_margin     = this->x_off;
  y_margin_Top = this->y_off_Top;
  y_margin_bot = this->y_off_bot;
  
  this->x_abs = x_in;
  this->y_abs = y_in;

  max_w  = 0;
  max_y  = 0;
  curr_x = this->x_abs + x_margin;
  curr_y = this->y_abs + y_margin_Top;

  /*** Record start of this set of columns ***/

  y_Top_column = curr_y;
  column_x     = curr_x;

  /*** Iterate over children, packing them first ***/

  node = (Control*) this->first_child ();
  while (node != NULL) {
    if (dynamic_cast<Panel*> (node) && !node->collapsible) { 
      /* Pad some space above fixed-size panels */
      curr_y += ITEMSPACING;
    } 
    else if (dynamic_cast<Column*> (node)) {
      curr_column = (Column*) node;
      curr_x   += max_w + 1 * x_margin;
      column_x  = curr_x;

      node->x_abs = curr_x;
      node->y_abs = y_Top_column;
      node->w     = 2;
      node->h     = curr_y - y_Top_column;

      curr_x  += x_margin * 1;
      curr_y  = y_Top_column;
      max_w = 0;

      node = (Control*) node->next ();
      continue;
    }
		
    node->pack (curr_x, curr_y);

    if (dynamic_cast<Panel*> (node)  && !node->collapsible)
      /* Pad some space below fixed-size panels */
      curr_y += ITEMSPACING;
    
    curr_y  += node->h;

    if (node->w > max_w) {
      max_w = node->w;
      if (curr_column != NULL)
	curr_column->w = max_w + x_margin;
    }

    if (curr_y > max_y) {
      max_y = curr_y;
      if (curr_column != NULL)
	curr_column->h = max_y - y_Top_column;
    }

    node = (Control*) node->next ();
    
    if (node) {
      curr_y += ITEMSPACING;
    }

  }

  if (this->is_container) {
    max_y += y_margin_bot;  /*** Add bottom border inside box */

    if (this->first_child ()) {
      this->w        = column_x + max_w + 2 * x_margin - x_in;
      this->h        = (max_y - y_in);
    }
    else  {            /* An empty container, so just assign default w & h */
      if (!dynamic_cast<Rollout*> (this) &&
           !dynamic_cast<Tree*> (this)) {
	this->w        = DEFAULT_CONTROL_WIDTH;
	this->h        = DEFAULT_CONTROL_HEIGHT;
      }
    }

    /** Expand panel if necessary (e.g., to include all the text in 
      a panel label) **/
    this->update_size ();   


    /*** Now we step through the Columns, setting the 'h'  ***/
    node = (Control*) this->first_child ();
    while (node != NULL) {
      if (dynamic_cast<Column*> (node)) {
	node->h = this->h - y_margin_bot - y_margin_Top;
      }

      node = (Control*) node->next ();
    }
  }
}



/******************************** Live Variables **************************/
/*********** Control::sync_live () ************/
/* Reads live variable and sets control to its current value                */
/* This function is recursive, and operates on control's children           */

void Control::sync_live (int recurse, int draw_it)
{
  Node *node;
  int        sync_it=true;
  int        i;
  float      *fp;
  bool       changed = false;

  /*** If this is currently active control, and mouse button is down,
    don't sync ***/
  if (glui)
  {
    if (this == glui->active_control AND glui->mouse_button_down)
      sync_it = false;

    /*** Actually, just disable syncing if button is down ***/
    /*** Nope, go ahead and sync if mouse is down - this allows syncing in
      callbacks ***/
    if (0) { /* THIS CODE BELOW SHOULD NOT BE EXECUTED */
      if (glui->mouse_button_down) {
	/* printf ("Can't sync\n");              */
	return;
      }
    }
  }

  /***  If this control has a live variable, we check its current value
    against the stored value in the control  ***/

  if (ptr_val != NULL) {
    if (live_type == LIVE_NONE OR NOT sync_it) {
    }
    else if (live_type == LIVE_INT) {
      if (* ((int*)ptr_val) != last_live_int) {
        set_int_val (* ((int*)ptr_val));
        last_live_int = * ((int*)ptr_val);
        changed = true;
      }
    }   
    else if (live_type == LIVE_FLOAT) {
      if (* ((float*)ptr_val) != last_live_float) {
        set_float_val (* ((float*)ptr_val));
        last_live_float = * ((float*)ptr_val);
        changed = true;
      }
    } 
    else if (live_type == LIVE_TEXT) {
      if (last_live_text.compare ((const char*)ptr_val) != 0) {
        set_text ((char*) ptr_val);
        last_live_text = (const char*)ptr_val;
        changed = true;
      }
    } 
    else if (live_type == LIVE_STRING) {
      if (last_live_text.compare (((std::string*) ptr_val)->c_str ()) != 0) {
        set_text (((std::string*) ptr_val)->c_str ());
        last_live_text = * ((std::string*) ptr_val);
        changed = true;
      }
    } 
    else if (live_type == LIVE_FLOAT_ARRAY) { 
      /***  Step through the arrays, and see if they're the same  ***/
      
      fp = (float*) ptr_val;
      for (i=0; i<float_array_size; i++) {
        if (*fp != last_live_float_array[i]) {
          changed = true;
          break;
        }
		
        fp++;
      }
      
      if (changed == true) {
        fp = (float*) ptr_val;
        set_float_array_val (fp);
        for (i=0; i<float_array_size; i++) {
          last_live_float_array[i] = *fp;
          fp++;
        }
      }
    }
    else if (live_type == LIVE_DOUBLE) {
    }
  }

  /***  If this control is changed and we're supposed to be drawing, then
    Draw it now    ***/
  if (changed == true AND draw_it) {
    redraw ();
  }

  if (recurse) {
    /*** Now recursively output live vars for all children ***/
    node = this->first_child ();
    while (node) {
 ((Control*) node)->sync_live (true, true);
      node = node->next ();
    }

    if (collapsible == true AND is_open == false) {
      /** Here we have a collapsed control (e.g., a rollout that is closed **/
      /** We need to go in and sync all the collapsed controls inside      **/
       
      node = this->collapsed_node.first_child ();
      while (node) {
	 ((Control*) node)->sync_live (true, false);
	node = node->next ();
      }
    }
  }
}


/********** Control::output_live () ************/
/* Writes current value of control to live variable.                         */

void Control::output_live (int update_main_gfx)
{
  int    i;
  float *fp;

  if (ptr_val == NULL)
    return;
   
  if (NOT live_inited) 
    return;
   
  if (live_type == LIVE_NONE) {
  }
  else if (live_type == LIVE_INT) {
    * ((int*)ptr_val) = int_val;
    last_live_int    = int_val;
  } 
  else if (live_type == LIVE_FLOAT) {
    * ((float*)ptr_val) = float_val;
    last_live_float    = float_val;
  } 
  else if (live_type == LIVE_TEXT) {
    strncpy ((char*) ptr_val, text.c_str (), text.length ()+1);
    last_live_text =  text;
  } 
  else if (live_type == LIVE_STRING) {
 (* (std::string*)ptr_val)= text.c_str ();
    last_live_text =  text;
  } 
  else if (live_type == LIVE_FLOAT_ARRAY) {
    fp = (float*) ptr_val;

    for (i=0; i<float_array_size; i++) {
      *fp                      = float_array_val[i];
      last_live_float_array[i] = float_array_val[i];
      fp++;
    }
  }
  else if (live_type == LIVE_DOUBLE) {
  }

  /** Update the main gfx window? **/
  if (update_main_gfx AND this->glui != NULL) {
    this->glui->post_update_main_gfx ();
  }
}


/****** Control::execute_callback () **********/

void Control::execute_callback ()
{
  int old_window;
  
  old_window = glutGetWindow ();

  if (glui AND glui->main_gfx_window_id != -1) 
    glutSetWindow (glui->main_gfx_window_id);

  this->callback (this);
//  if (this->callback) 
//    this->callback (this->user_id);

  glutSetWindow (old_window);
}


/************** Control::init_live () **********/
/* Reads in  value of a live variable.  Called once, when ctrl is created   */

void Control::init_live ()
{
  int    i;
  float *fp;

  if (ptr_val == NULL)
    return;

  if (live_type == LIVE_NONE) {
  }
  else if (live_type == LIVE_INT) {
    set_int_val (* ((int*)ptr_val));
    last_live_int = * ((int*)ptr_val);
  } 
  else if (live_type == LIVE_FLOAT) {
    set_float_val (* ((float*)ptr_val));
    last_live_float = * ((float*)ptr_val);
  } 
  else if (live_type == LIVE_TEXT) {
    set_text ((const char*) ptr_val);
    last_live_text = (const char*) ptr_val;
  }
  else if (live_type == LIVE_STRING) {
    set_text (((std::string*) ptr_val)->c_str ());
    last_live_text = ((std::string*) ptr_val)->c_str ();
  }
  else if (live_type == LIVE_FLOAT_ARRAY) {
    set_float_array_val ((float*) ptr_val);

    fp = (float*) ptr_val;

    for (i=0; i<float_array_size; i++) {
      last_live_float_array[i] = *fp;
      fp++;
    }

  }
  else if (live_type == LIVE_DOUBLE) {
  }

  live_inited = true;
}

/***** Control::set_float_array_val () ********/

void  Control::set_float_array_val (float *array_ptr)
{
  int i;

  if (array_ptr == NULL)
    return;

  for (i=0; i<float_array_size; i++) {
    float_array_val[i] = array_ptr[i];
  }

  /*** Output the live auto, without updating the main gfx window ***/
  output_live (false);
}


/***** Control::get_float_array_val () ********/

void  Control::get_float_array_val (float *array_ptr)
{
  int i;

  if (array_ptr == NULL)
    return;

  for (i=0; i<float_array_size; i++) {
    array_ptr[i] = float_array_val[i];
  }
}



/**************************** Little Utility Routines ********************/

/**** Control::set_name () ********************/

void   Control::set_name (const char *str)
{
  name = str;
  redraw (); 
}

/**** Control::enable () ****************/

void Control::enable ()
{
  Control *node;

  enabled = true;
   
  if (NOT glui)
    return;

  redraw ();

  /*** Now recursively enable all buttons below it ***/
  node = (Control*) first_child ();
  while (node)
  {
    node->enable ();
    node = (Control*) node->next ();
  }
}


/***** Control::disable () ****************/

void Control::disable ()
{
  Control *node;

  enabled = false;
  
  if (NOT glui)
    return;

  if (glui->active_control == this)
    glui->deactivate_current_control ();
  redraw ();

  /*** Now recursively disable all buttons below it ***/
  node = (Control*) first_child ();
  while (node) {
    node->disable ();
    node = (Control*) node->next ();
  }
}

/******* Control::set_w () **************/

void Control::set_w (int new_w)
{
  w = new_w;
  update_size ();  /* Make sure control is big enough to fit text */
  if (glui) glui->refresh ();
}


/**** Control::set_h () **************/

void Control::set_h (int new_h)
{
  h = new_h;
  update_size ();  /* Make sure control is big enough to fit text */
  if (glui) glui->refresh ();
}


/***** Control::set_alignment () ******/

void Control::set_alignment (int new_align)
{
  alignment = new_align;

  if (glui)
  {
    glui->align_controls (this);
    redraw_window ();
  }
}


/***** Control::needs_idle () *********/
/* This method gets overloaded by specific classes, e.g. Spinner.            */
/* It returns whether or not a control needs to receive an idle event or not */
/* For example, a spinner only needs idle events when the user is holding    */
/* the mouse down in one of the arrows.  Otherwise, don't waste cycles       */
/* and OpenGL context switching by calling its idle.                         */

bool Control::needs_idle () const
{ 
  return false; 
}


/********* Control::~Control () **********/

Control::~Control ()
{
  Control *item = (Control*) this->first_child ();

  while (item) 
  {
    Control *tmp = item;
    item = (Control*) item->next ();
    delete tmp;
  }
}

/********* Control::hide_internal () ********/
/** Sets hidden==true for this  control and all its siblings.             */
/**  If recurse is true, we go to children as well                       */

void         Control::hide_internal (int recurse)
{
  Node *node;

  node = (Node *) this;
  while (node != NULL) {
 ((Control*)node)->hidden = true;

    if (recurse AND node->first_child () != NULL)  
 ((Control*) node->first_child ())->hide_internal (true);
      
    node = node->next ();
  }

  node = this->collapsed_node.first_child ();
  while (node != NULL) {
 ((Control*)node)->hidden = true;

    if (recurse AND node->first_child () != NULL)  
 ((Control*) node->first_child ())->hide_internal (true);
      
    node = node->next ();
  }
}


/********* Control::unhide_internal () ********/
/** Sets hidden==false for this  control and all its siblings.             */
/**  If recurse is true, we go to children as well                       */

void         Control::unhide_internal (int recurse)
{
  Node *node;

  node = (Node *) this;
  while (node != NULL) {
    /*    printf ("unhide: %s [%d]\n", ((Control*)node)->name.c_str (), 
	 ((Control*)node)->hidden);*/
 ((Control*)node)->hidden = false;

    if (recurse AND node->first_child () != NULL)  
 ((Control*) node->first_child ())->unhide_internal (true);
      
    node = node->next ();
  }

  node = this->collapsed_node.first_child ();
  while (node != NULL) {
 ((Control*)node)->hidden = false;

    if (recurse AND node->first_child () != NULL)  
 ((Control*) node->first_child ())->unhide_internal (true);
      
    node = node->next ();
  }
}
