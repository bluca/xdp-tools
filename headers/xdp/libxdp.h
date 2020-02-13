// SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause)

/*
 * XDP management utility functions
 *
 * Copyright (C) 2020 Toke Høiland-Jørgensen <toke@redhat.com>
 */

#include <linux/bpf.h>
#include <bpf/bpf.h>
#include "xdp_helpers.h"

struct xdp_program;

struct xdp_program *xdp_program__from_bpf_obj(struct bpf_object *obj,
					      const char *prog_name);
struct xdp_program *xdp_program__open_file(const char *filename,
					   const char *prog_name,
					   struct bpf_object_open_opts *opts);
struct xdp_program *xdp_program__from_id(__u32 prog_id);

struct xdp_program *xdp_program__new();
void xdp_program__free(struct xdp_program *xdp_prog);

const char *xdp_program__name(struct xdp_program *xdp_prog);
unsigned int xdp_program__run_prio(struct xdp_program *xdp_prog);
bool xdp_program__chain_call_enabled(struct xdp_program *xdp_prog,
				     enum xdp_action action);

int xdp_program__print_chain_call_actions(struct xdp_program *prog,
					  char *buf,
					  size_t buf_len);
