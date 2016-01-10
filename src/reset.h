/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_RESET_H
#define HHVM_GIT2_RESET_H

#include "../ext_git2.h"

using namespace HPHP;

int64_t HHVM_FUNCTION(git_reset,
	const Resource& repo,
	const Resource& target,
	int64_t reset_type);

int64_t HHVM_FUNCTION(git_reset_default,
	const Resource& repo,
	const Resource& target,
	const Resource& pathspecs);

#endif

