/* 
 * Copyright (C) 2002-2010 XimpleWare, info@ximpleware.com
 *
 * This program is free software; you can redistribute it and/or modify
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
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */
// vtd-xml.cpp : Defines the entry point for the console application.
//

#include "everything.h"

using namespace com_ximpleware;

// change element names
int main(){
	char *xml = "<aaaa> <bbbbb> <ccccc> </ccccc> <ccccc/> <ccccc></ccccc> </bbbbb> </aaaa>";
	VTDGen vg;
	vg.setDoc(xml,strlen(xml));
	vg.parse(false);
	VTDNav *vn = vg.getNav();
	AutoPilot ap(vn);
	ap.selectXPath(L"//*");
	XMLModifier xm(vn);
	int i;
	while((i=ap.evalXPath())!=-1){         
		xm.updateElementName(L"lalalala");   
	}
	xm.output("c:/xml/lala.xml");

	return 0;
}