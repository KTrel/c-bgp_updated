// ==================================================================
// @(#)RouteEntry.java
//
// @author Bruno Quoitin (bruno.quoitin@uclouvain.be)
// @date 01/09/2008
// $Id$
//
// C-BGP, BGP Routing Solver
// Copyright (C) 2002-2008 Bruno Quoitin
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
// 02111-1307  USA
// ==================================================================

package be.ac.ucl.ingi.cbgp;

public class RouteEntry {

	public final IPAddress oif;
	public final IPAddress gateway;
	
	// -----[ constructor ]-----------------------------------------
	public RouteEntry(IPAddress oif, IPAddress gateway) {
		this.oif= oif;
		this.gateway= gateway;
    }

}
