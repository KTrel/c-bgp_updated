// ==================================================================
// @(#) origin.h
//
// @author Bruno Quoitin (bruno.quoitin@uclouvain.be)
// @data 18/12/2009
// $Id: origin.h,v 1.1 2009-03-24 13:41:26 bqu Exp $
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

#ifndef __BGP_ATTR_ORIGIN_H__
#define __BGP_ATTR_ORIGIN_H__

#include <bgp/types.h>

#ifdef _cplusplus
extern "C" {
#endif

  // -----[ bgp_origin_from_str ]------------------------------------
  int bgp_origin_from_str(const char * str, bgp_origin_t * origin_ref);

  // -----[ bgp_origin_to_str ]--------------------------------------
  const char * bgp_origin_to_str(bgp_origin_t origin);

#ifdef _cplusplus
}
#endif

#endif /* __BGP_ATTR_ORIGIN_H__ */