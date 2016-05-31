// ==================================================================
// @(#)export_graphviz.c
//
// @author Bruno Quoitin (bruno.quoitin@uclouvain.be)
// @date 01/09/08
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

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <net/export_graphviz.h>
#include <net/link-list.h>
#include <net/node.h>
#include <net/subnet.h>

// -----[ net_export_dot ]-------------------------------------------
net_error_t net_export_dot(gds_stream_t * stream, network_t * network)
{
  gds_enum_t * nodes, * subnets;
  net_node_t * node;
  net_subnet_t * subnet;
  net_iface_t * iface;
  unsigned int index;

  // Header
  stream_printf(stream, "/**\n");
  stream_printf(stream, " * Network topology graphviz dot file\n");
  stream_printf(stream, " * generated by C-BGP\n");
  stream_printf(stream, " *\n");
  stream_printf(stream, " * Render with: neato -Tps <file.dot> <file.ps>\n");
  stream_printf(stream, " */\n");
  stream_printf(stream, "graph G {\n");
  stream_printf(stream, "  overlap=scale\n");

  // Nodes
  nodes= trie_get_enum(network->nodes);
  while (enum_has_next(nodes)) {
    node= *((net_node_t **) enum_get_next(nodes));
    stream_printf(stream, "  \"");
    node_dump_id(stream, node);
    stream_printf(stream, "\" [");
    stream_printf(stream, "shape=box");
    stream_printf(stream, "] ;\n");
  }
  enum_destroy(&nodes);

  // Subnets
  subnets= _array_get_enum((array_t *) network->subnets);
  while (enum_has_next(subnets)) {
    subnet= *((net_subnet_t **) enum_get_next(subnets));
    stream_printf(stream, "  \"");
    subnet_dump_id(stream, subnet);
    stream_printf(stream, "\" [");
    stream_printf(stream, "shape=ellipse");
    stream_printf(stream, "] ;\n");
  }
  enum_destroy(&subnets);

  // Links
  nodes= trie_get_enum(network->nodes);
  while (enum_has_next(nodes)) {
    node= *((net_node_t **) enum_get_next(nodes));
    for (index= 0; index < net_ifaces_size(node->ifaces); index++) {
      iface= (net_iface_t *) node->ifaces->data[index];
      switch (iface->type) {
      case NET_IFACE_RTR:
	if (node->rid > iface->dest.iface->owner->rid)
	  continue;
	stream_printf(stream, "  \"");
	node_dump_id(stream, node);
	stream_printf(stream, "\" -- \"");
	node_dump_id(stream, iface->dest.iface->owner);
	stream_printf(stream, "\" [label=\"%u/%u,%u/%u\",dir=both] ;\n",
		      net_iface_get_metric(iface, 0),
		      net_iface_get_metric(iface->dest.iface, 0),
		      net_iface_get_load(iface),
		      net_iface_get_load(iface->dest.iface));
	break;
      case NET_IFACE_PTP:
	if (node->rid > iface->dest.iface->owner->rid)
	  continue;
	stream_printf(stream, "  \"");
	node_dump_id(stream, node);
	stream_printf(stream, "\" -- \"");
	node_dump_id(stream, iface->dest.iface->owner);
	stream_printf(stream, "\" [label=\"%u/%u,%u/%u\",dir=both] ;\n",
		      net_iface_get_metric(iface, 0),
		      net_iface_get_metric(iface->dest.iface, 0),
		      net_iface_get_load(iface),
		      net_iface_get_load(iface->dest.iface));
	break;
      case NET_IFACE_PTMP:
	stream_printf(stream, "  \"");
	node_dump_id(stream, node);
	stream_printf(stream, "\" -- \"");
	subnet_dump_id(stream, iface->dest.subnet);
	stream_printf(stream, "\" [label=\"%u,%u\",dir=forward] ;\n",
		      net_iface_get_metric(iface, 0),
		      net_iface_get_load(iface));
	break;
      default:
	;
      }

    }
  }
  enum_destroy(&nodes);

  stream_printf(stream, "}\n");
  return ESUCCESS;
}
