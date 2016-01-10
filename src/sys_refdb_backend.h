/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_SYS_REFDB_BACKEND_H
#define HHVM_GIT2_SYS_REFDB_BACKEND_H

#include "../ext_git2.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_refdb_backend_fs,
	const Resource& repo);

int64_t HHVM_FUNCTION(git_refdb_set_backend,
	const Resource& refdb,
	const Resource& backend);

#endif

