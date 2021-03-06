/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_COMMON_H
#define HHVM_GIT2_COMMON_H

#include "../ext_git2.h"

using namespace HPHP;

void HHVM_FUNCTION(git_libgit2_version,
	int64_t major,
	int64_t minor,
	int64_t rev);

int64_t HHVM_FUNCTION(git_libgit2_capabilities);

int64_t HHVM_FUNCTION(git_libgit2_opts,
	int64_t option);

#endif

