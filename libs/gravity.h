/* -*-c-*- */
/* This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef GRAVITY_H
#define GRAVITY_H

/* ---------------------------- included header files ----------------------- */

/* ---------------------------- global definitions -------------------------- */

/* ---------------------------- global macros ------------------------------- */

/* ---------------------------- type definitions ---------------------------- */

typedef enum
{
	DIR_NONE = -1,
	DIR_N = 0,
	DIR_E = 1,
	DIR_S = 2,
	DIR_W = 3,
	DIR_MAJOR_MASK = 3,
	DIR_NE = 4,
	DIR_SE = 5,
	DIR_SW = 6,
	DIR_NW = 7,
	DIR_MASK = 7,
	DIR_C = 8,
	DIR_ALL_MASK = 8,
} direction_type;

typedef enum
{
	MULTI_DIR_NONE = 0,
	MULTI_DIR_FIRST = (1 << DIR_N),
	MULTI_DIR_N =     (1 << DIR_N),
	MULTI_DIR_E =     (1 << DIR_E),
	MULTI_DIR_S =     (1 << DIR_S),
	MULTI_DIR_W =     (1 << DIR_W),
	MULTI_DIR_NE =    (1 << DIR_NE),
	MULTI_DIR_SE =    (1 << DIR_SE),
	MULTI_DIR_SW =    (1 << DIR_SW),
	MULTI_DIR_NW =    (1 << DIR_NW),
	MULTI_DIR_ALL =  ((1 << (DIR_MASK + 1)) - 1),
	MULTI_DIR_C =     (1 << DIR_C),
	MULTI_DIR_LAST =  (1 << DIR_ALL_MASK)
} multi_direction_type;

typedef enum
{
	ROTATION_0    = 0,
	ROTATION_90   = 1,
	ROTATION_180  = 2,
	ROTATION_270  = 3,
	ROTATION_MASK = 3
} rotation_type;

/* ---------------------------- exported variables (globals) ---------------- */

/* ---------------------------- interface functions ------------------------- */

void gravity_get_offsets(int grav, int *xp,int *yp);
void gravity_move(int gravity, rectangle *rect, int xdiff, int ydiff);
void gravity_resize(int gravity, rectangle *rect, int wdiff, int hdiff);
void gravity_move_resize_parent_child(
	int child_gravity, rectangle *parent_diff_r, rectangle *child_r);
direction_type gravity_grav_to_dir(
	int grav);
int gravity_dir_to_grav(
	direction_type dir);
int gravity_combine_xy_grav(
	int grav_x, int grav_y);
void gravity_split_xy_grav(
	int *ret_grav_x, int *ret_grav_y, int in_grav);
int gravity_combine_xy_dir(
	int dir_x, int dir_y);
void gravity_split_xy_dir(
	int *ret_dir_x, int *ret_dir_y, int in_dir);
int gravity_dir_to_sign_one_axis(
	direction_type dir);
direction_type gravity_parse_dir_argument(
	char *action, char **ret_action, direction_type default_ret);
multi_direction_type gravity_parse_multi_dir_argument(
	char *action, char **ret_action);
void gravity_get_next_multi_dir(int dir_set, multi_direction_type *dir);
direction_type gravity_multi_dir_to_dir(multi_direction_type mdir);
void gravity_rotate_xy(rotation_type rot, int x, int y, int *ret_x, int *ret_y);

#endif /* GRAVITY_H */
