/*
 * HypView - (c)      - 2006 Philipp Donze
 *               2006 -      Philipp Donze & Odd Skancke
 *
 * A replacement hypertext viewer
 *
 * This file is part of HypView.
 *
 * HypView is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * HypView is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with HypView; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <gem.h>
#include "diallib.h"

#if USE_MENU == YES

void ChooseMenu(short title, short entry)
{
	if((menu_tree[title].ob_state&DISABLED)||
			(menu_tree[entry].ob_state&DISABLED))	/*	Wenn Menutitel inaktiv...	*/
		return;												/*	... tschuess	*/

	menu_tnormal(menu_tree,title,0);
	SelectMenu(title,entry);
	menu_tnormal(menu_tree,title,1);
}

#endif
