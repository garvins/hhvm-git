/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_CLONE_H
#define HHVM_GIT2_CLONE_H

#include "../ext_git2.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_clone,
	const String& url,
	const String& local_path,
	const Array& options = null_array);

int64_t HHVM_FUNCTION(git_clone_into,
	const Resource& repo,
	const Resource& remote,
	const Array& co_opts,
	const String& branch);

#endif

