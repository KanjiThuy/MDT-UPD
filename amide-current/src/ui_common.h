/* ui_common.h
 *
 * Part of amide - Amide's a Medical Image Dataset Examiner
 * Copyright (C) 2001-2003 Andy Loening
 *
 * Author: Andy Loening <loening@alum.mit.edu>
 */

/*
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2, or (at your option)
  any later version.
 
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
 
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
  02111-1307, USA.
*/

/* header files that are always needed with this file */
#include <gtk/gtk.h>
#include <libgnomecanvas/libgnomecanvas.h>
#include <libgnomeui/libgnomeui.h>
#include "amitk_point.h"

#define UI_COMMON_ROI_MODE_CURSOR GDK_DRAFT_SMALL
#define UI_COMMON_ROI_RESIZE_CURSOR GDK_SIZING
#define UI_COMMON_ROTATE_CURSOR GDK_EXCHANGE
#define UI_COMMON_SHIFT_CURSOR GDK_FLEUR
#define UI_COMMON_ROI_ISOCONTOUR_CURSOR GDK_DRAFT_SMALL
#define UI_COMMON_ROI_ERASE_CURSOR GDK_DRAFT_SMALL
#define UI_COMMON_DATA_SET_MODE_CURSOR GDK_CROSSHAIR
#define UI_COMMON_FIDUCIAL_MARK_MODE_CURSOR GDK_DRAFT_SMALL
#define UI_COMMON_WAIT_CURSOR GDK_WATCH

typedef enum {
  UI_CURSOR_DEFAULT,
  UI_CURSOR_ROI_MODE,
  UI_CURSOR_ROI_RESIZE,
  UI_CURSOR_ROI_ROTATE,
  UI_CURSOR_OBJECT_SHIFT,
  UI_CURSOR_ROI_ISOCONTOUR,
  UI_CURSOR_ROI_ERASE,
  UI_CURSOR_DATA_SET_MODE, 
  UI_CURSOR_FIDUCIAL_MARK_MODE,
  UI_CURSOR_RENDERING_ROTATE_XY,
  UI_CURSOR_RENDERING_ROTATE_Z, 
  UI_CURSOR_WAIT,
  NUM_CURSORS
} ui_common_cursor_t;


/* external functions */
gboolean ui_common_check_filename(const gchar * filename);
void ui_common_entry_name_cb(gchar * entry_string, gpointer data);
void ui_common_file_selection_cancel_cb(GtkWidget* widget, gpointer data);
gchar * ui_common_file_selection_get_save_name(GtkWidget * file_selection);
gchar * ui_common_xif_selection_get_save_name(GtkWidget * xif_selection);
gchar * ui_common_file_selection_get_load_name(GtkWidget * file_selection);
gchar * ui_common_xif_selection_get_load_name(GtkWidget * xif_selection);
void ui_common_file_selection_set_filename(GtkWidget * file_selection, gchar * suggested_name);
void ui_common_xif_selection_set_filename(GtkWidget * xif_selection, gchar * suggested_name);
void ui_common_about_cb(GtkWidget * button, gpointer data);
void ui_common_draw_view_axis(GnomeCanvas * canvas, gint row, gint column, 
			      AmitkView view, AmitkLayout layout, 
			      gint axis_width, gint axis_height);
GtkWidget * ui_common_create_view_axis_indicator(AmitkLayout layout);
void ui_common_window_realize_cb(GtkWidget * widget, gpointer data);
void ui_common_place_cursor_no_wait(ui_common_cursor_t which_cursor, GtkWidget * widget);
void ui_common_place_cursor(ui_common_cursor_t which_cursor, GtkWidget * widget);
void ui_common_remove_cursor(ui_common_cursor_t which_cursor, GtkWidget * widget);
GtkWidget * ui_common_entry_dialog(GtkWindow * parent, gchar * prompt, gchar **return_str_ptr);



/* external variables */
extern GnomeUIInfo ui_common_help_menu[];
extern GdkCursor * ui_common_cursor[NUM_CURSORS];
