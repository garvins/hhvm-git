/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_REFDB_H
#define HHVM_GIT2_REFDB_H

#include "../ext_git2.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_refdb_new,
	const Resource& repo);

Resource HHVM_FUNCTION(git_refdb_open,
	const Resource& repo);

int64_t HHVM_FUNCTION(git_refdb_compress,
	const Resource& refdb);

void HHVM_FUNCTION(git_refdb_free,
	const Resource& refdb);

#endif

