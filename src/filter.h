/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_FILTER_H
#define HHVM_GIT2_FILTER_H

#include "../ext_git2.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_filter_list_load,
	const Resource& repo,
	const Resource& blob,
	const String& path,
	int64_t mode);

Resource HHVM_FUNCTION(git_filter_list_apply_to_data,
	const Resource& filters,
	const Resource& in);

Resource HHVM_FUNCTION(git_filter_list_apply_to_file,
	const Resource& filters,
	const Resource& repo,
	const String& path);

Resource HHVM_FUNCTION(git_filter_list_apply_to_blob,
	const Resource& filters,
	const Resource& blob);

void HHVM_FUNCTION(git_filter_list_free,
	const Resource& filters);

#endif

