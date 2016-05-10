/****************************************************************************
  
  GLUI User Interface Toolkit
  ---------------------------

     statictext.cpp - StaticText Control


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

/****************************** StaticText::StaticText () **********/
StaticText::StaticText (Node *parent, const char *name)
{
  common_init ();
  set_name (name);
  parent->add_control (this);
}

/****************************** StaticText::Draw () **********/

void    StaticText::Draw (int x, int y)
{
  DRAWINGSENTINAL_IDIOM

  draw_text ();
}


/****************************** StaticText::set_text () **********/

void    StaticText::set_text (const char *text)
{
  set_name (text);
  redraw ();
}


/************************************ StaticText::update_size () **********/

void   StaticText::update_size (void)
{
  int text_size;

  if (NOT glui)
    return;

  text_size = string_width (name);

  if (w < text_size)
    w = text_size;    
}


/****************************** StaticText::draw_text () **********/

void    StaticText::draw_text (void)
{
  if (NOT can_draw ())
    return;

  erase_text ();
  draw_name (0, 9);
}


/****************************** StaticText::erase_text () **********/

void    StaticText::erase_text (void)
{
  if (NOT can_draw ())
    return;

  set_To_bkgd_color ();
  glDisable (GL_CULL_FACE);
  glBegin (GL_TRIANGLES);
  glVertex2i (0,0);   glVertex2i (w, 0);  glVertex2i (w, h);  
  glVertex2i (0, 0);  glVertex2i (w, h);  glVertex2i (0, h);   
  glEnd ();
}



