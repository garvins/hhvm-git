/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_STATUS_H
#define HHVM_GIT2_STATUS_H

#include "../ext_git2.h"

using namespace HPHP;

int64_t HHVM_FUNCTION(git_status_foreach,
	const Resource& repo,
	const Variant& callback,
	const Variant& payload);

int64_t HHVM_FUNCTION(git_status_foreach_ext,
	const Resource& repo,
	const Resource& opts,
	const Variant& callback,
	const Variant& payload);

int64_t HHVM_FUNCTION(git_status_file,
	int64_t status_flags,
	const Resource& repo,
	const String& path);

Resource HHVM_FUNCTION(git_status_list_new,
	const Resource& repo,
	const Resource& opts);

int64_t HHVM_FUNCTION(git_status_list_entrycount,
	const Resource& statuslist);

Resource HHVM_FUNCTION(git_status_byindex,
	const Resource& statuslist,
	int64_t idx);

void HHVM_FUNCTION(git_status_list_free,
	const Resource& statuslist);

int64_t HHVM_FUNCTION(git_status_should_ignore,
	int64_t ignored,
	const Resource& repo,
	const String& path);

#endif

