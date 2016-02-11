/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_PUSH_H
#define HHVM_GIT2_PUSH_H

#include "../ext_git2.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_push_new,
	const Resource& remote);

int64_t HHVM_FUNCTION(git_push_set_options,
	const Resource& push,
	const Array& opts = null_array);

int64_t HHVM_FUNCTION(git_push_set_callbacks,
	const Resource& push,
	const Variant& pack_progress_cb,
	const Variant& pack_progress_cb_payload,
	const Variant& transfer_progress_cb,
	const Variant& transfer_progress_cb_payload);

int64_t HHVM_FUNCTION(git_push_add_refspec,
	const Resource& push,
	const String& refspec);

int64_t HHVM_FUNCTION(git_push_update_tips,
	const Resource& push);

int64_t HHVM_FUNCTION(git_push_finish,
	const Resource& push);

int64_t HHVM_FUNCTION(git_push_unpack_ok,
	const Resource& push);

int64_t HHVM_FUNCTION(git_push_status_foreach,
	const Resource& push,
	const Variant& cb,
	const Variant& data);

void HHVM_FUNCTION(git_push_free,
	const Resource& push);

#endif

