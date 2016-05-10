/****************************************************************************

  GLUI User Interface Toolkit 
  ---------------------------

     add_controls.cpp - Routines for adding controls to a GLUI window

Note: these routines are all deprecated.  Keeping them all here
prevents the linker from dragging in all the .o files, even for controls
that aren't used.

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

#include "_GUI/UI.h"
#include "_GUI/Internal.h"


/*********************************** GLUI::AddCheckBox () ************/

Checkbox *GLUI::AddCheckBox (const char *name, int *value_ptr, int id, CB callback)
{
  return addCheckBoxToPanel (mainPanel, name, value_ptr, id, callback);
}


/*********************************** GLUI::AddCheckBoxToPanel () **********/

Checkbox *GLUI::AddCheckBoxToPanel (Panel *panel, const char *name, int *value_ptr, int id, CB callback)
{
  return new Checkbox (panel, name, value_ptr, id, callback);
}

/********************************************* GLUI::AddPanel () *************/

Panel *GLUI::AddPanel (const char *name, int type)
{
  return addPanelToPanel (mainPanel, name, type);
}


/**************************************** GLUI::AddPanelToPanel () *********/

Panel *GLUI::AddPanelToPanel (Panel *parentPanel, const char *name, int type)
{
  return new Panel (parentPanel, name, type);
}


/***************************** GLUI::Add_radiogroup () ***************/

RadioGroup *GLUI::Add_radiogroup (int *value_ptr, int user_id, CB callback)
{
  return add_radiogroupToPanel (mainPanel, value_ptr,
				  user_id, callback);
}


/***************************** GLUI::Add_radiogroupToPanel () ***************/

RadioGroup *GLUI::Add_radiogroupToPanel (
  Panel *panel, int *value_ptr,
  int user_id, CB callback
)
{
  return new RadioGroup (panel, value_ptr, user_id, callback);
}


/***************************** GLUI::Add_radiobuttonTo_group () *************/

RadioButton *GLUI::Add_radiobuttonTo_group (RadioGroup *group,
                                                   const char *name)
{
  return new RadioButton (group, name);
}


/********************************** GLUI::Add_statictext () ************/

StaticText *GLUI::Add_statictext (const char *name)
{
  return add_statictextToPanel (mainPanel, name);
}


/******************************* GLUI::Add_statictextToPanel () **********/

StaticText *GLUI::Add_statictextToPanel (Panel *panel, 
                                                const char *name)
{
  return new StaticText (panel, name);
}


/***************************************** GLUI::Add_button () ************/

Button *GLUI::Add_button (const char *name, 
				  int id, CB callback)
{
  return add_buttonToPanel (mainPanel, name, id, callback);
}

/*********************************** GLUI::Add_buttonToPanel () **********/

Button *GLUI::Add_buttonToPanel (Panel *panel, const char *name, int id, CB callback)
{
  return new Button (panel, name, id, callback);
}

/********************************** GLUI::Add_separator () ************/

void GLUI::Add_separator (void)
{
  add_separatorToPanel (mainPanel);
}


/******************************* GLUI::Add_separatorToPanel () **********/

void GLUI::Add_separatorToPanel (Panel *panel)
{
  new Separator (panel);
}


/********************************** GLUI::Add_edittext () ************/

EditText *GLUI::Add_edittext (const char *name, int data_type, void *data, int id, CB callback)
{
  return add_edittextToPanel (mainPanel, name, data_type, data,
                                id, callback);
}


/******************************* GLUI::Add_edittextToPanel () **********/

EditText *GLUI::Add_edittextToPanel (Panel *panel, const char *name, int data_type, void *data, int id, CB callback)
{
  return new EditText (panel, name, data_type, data, id, callback);
}

/********************************** GLUI::Add_edittext () ************/

EditText  *GLUI::Add_edittext (const char *name, String & data, int id, CB callback)
{
  return add_edittextToPanel (mainPanel, name, data, id, callback);
}


/******************************* GLUI::Add_edittextToPanel () **********/

EditText*
GLUI::Add_edittextToPanel (Panel *panel, const char *name, 
                             String& data,
                             int id, CB callback)
{
  return new EditText (panel, name, EDITTEXT_STRING, &data, id, callback);
}

/********************************** GLUI::Add_spinner () ************/

Spinner  *GLUI::Add_spinner (const char *name, 
				  int data_type, void *data,
				  int id, CB callback)
{
  return add_spinnerToPanel (mainPanel, name, data_type, data,
			       id, callback);
}


/******************************* GLUI::Add_spinnerToPanel () **********/

Spinner  *GLUI::Add_spinnerToPanel (
  Panel *panel, const char *name, 
  int data_type, void *data,
  int id, CB callback
)
{
  return new Spinner (panel, name, data_type, data, id, callback);
}


/********************************** GLUI::Add_column () ************/

void   GLUI::Add_column (int draw_bar)
{
  add_columnToPanel (mainPanel, draw_bar);
}


/******************************* GLUI::Add_columnToPanel () **********/

void   GLUI::Add_columnToPanel (Panel *panel, int draw_bar)
{
  new Column (panel, draw_bar);
}


/*********************************** GLUI::Add_listbox () ************/

Listbox   *GLUI::Add_listbox (const char *name, int *value_ptr,
				    int id, CB callback)
{
  return add_listboxToPanel (mainPanel,
                               name, value_ptr, id, callback);
}


/*********************************** GLUI::Add_listboxToPanel () **********/

Listbox   *GLUI::Add_listboxToPanel (Panel *panel,
                                            const char *name, int *value_ptr,
                                            int id, 
                                            CB callback)
{
  return new Listbox (panel, name, value_ptr, id, callback);
}


/*********************************** GLUI::Add_rotation () ************/

Rotation   *GLUI::Add_rotation (const char *name, float *value_ptr,
                                      int id, CB callback)
{
  return add_rotationToPanel (mainPanel, name, value_ptr, id, callback);
}


/*********************************** GLUI::Add_rotationToPanel () **********/

Rotation *GLUI::Add_rotationToPanel (Panel *panel,
                                            const char *name, float *value_ptr,
                                            int id, 
                                            CB callback)
{
  return new Rotation (panel, name, value_ptr, id, callback);
}


/*********************************** GLUI::Add_translation () ************/

Translation *GLUI::Add_translation (const char *name, int trans_type,
                                          float *value_ptr, int id, 
                                          CB callback)
{
  return add_translationToPanel (mainPanel,name,trans_type, 
                                   value_ptr, id, callback);
}


/*********************************** GLUI::Add_translationToPanel () **********/

Translation *GLUI::Add_translationToPanel (
  Panel *panel, const char *name, 
  int trans_type, float *value_ptr,
  int id, CB callback 
)
{
  return new Translation (panel, name, trans_type, value_ptr, id, callback);
}


/********************************** GLUI::Add_rollout () **************/

Rollout   *GLUI::Add_rollout (const char *name, int open, int type)
{
  return add_rolloutToPanel (mainPanel, name, open, type);
}


/****************************** GLUI::Add_rolloutToPanel () *********/

Rollout *GLUI::Add_rolloutToPanel (Panel *panel, const char *name,
                                         int open, int type)
{
  return new Rollout (panel, name, open, type);
}



