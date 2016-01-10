/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_REVPARSE_H
#define HHVM_GIT2_REVPARSE_H

#include "../ext_git2.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_revparse_single,
	const Resource& repo,
	const String& spec);

Resource HHVM_FUNCTION(git_revparse_ext,
	const Resource& repo,
	const String& spec);

int64_t HHVM_FUNCTION(git_revparse,
	const Resource& revspec,
	const Resource& repo,
	const String& spec);

#endif

