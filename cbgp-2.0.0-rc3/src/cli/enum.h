// ==================================================================
// @(#)enum.h
//
// Enumeration functions used by the CLI.
//
// @author Bruno Quoitin (bruno.quoitin@uclouvain.be), 
//
// @date 27/04/2007
// $Id: enum.h,v 1.7 2009-08-31 09:37:41 bqu Exp $
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

#ifndef __CLI_ENUM_H__
#define __CLI_ENUM_H__

#include <net/net_types.h>
#include <bgp/types.h>

#ifdef __cplusplus
extern "C" {
#endif

  // -----[ cli_enum_net_nodes ]-------------------------------------
  net_node_t * cli_enum_net_nodes(const char * text, int state);
  // -----[ cli_enum_net_nodes_id ]----------------------------------
  net_node_t * cli_enum_net_nodes_id(const char * text, int state);
  // -----[ cli_enum_bgp_routers ]-----------------------------------
  bgp_router_t * cli_enum_bgp_routers(const char * text, int state);
  // -----[ cli_enum_bgp_peers ]-------------------------------------
  bgp_peer_t * cli_enum_bgp_peers(const char * text, int state);

  // -----[ cli_enum_net_nodes_addr ]--------------------------------
  char * cli_enum_net_nodes_addr(const char * text, int state);
  // -----[ cli_enum_net_nodes_addr_id ]-----------------------------
  char * cli_enum_net_nodes_addr_id(const char * text, int state);
  // -----[ cli_enum_bgp_routers_addr ]------------------------------
  char * cli_enum_bgp_routers_addr(const char * text, int state);
  // -----[ cli_enum_bgp_routers_addr_id ]---------------------------
  char * cli_enum_bgp_routers_addr_id(const char * text, int state);
  // -----[ cli_enum_bgp_peers_addr ]--------------------------------
  char * cli_enum_bgp_peers_addr(const char * text, int state);

  // -----[ cli_enum_ctx_bgp_router ]--------------------------------
  void cli_enum_ctx_bgp_router(bgp_router_t * router);


#ifdef __cplusplus
}
#endif

#endif /** __CLI_ENUM_H__ */
