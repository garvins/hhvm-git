/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_SYS_REPOSITORY_H
#define HHVM_GIT2_SYS_REPOSITORY_H

#include "../ext_git2.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_repository_new);

void HHVM_FUNCTION(git_repository__cleanup,
	const Resource& repo);

int64_t HHVM_FUNCTION(git_repository_reinit_filesystem,
	const Resource& repo,
	int64_t recurse_submodules);

void HHVM_FUNCTION(git_repository_set_config,
	const Resource& repo,
	const Resource& config);

void HHVM_FUNCTION(git_repository_set_odb,
	const Resource& repo,
	const Resource& odb);

void HHVM_FUNCTION(git_repository_set_refdb,
	const Resource& repo,
	const Resource& refdb);

void HHVM_FUNCTION(git_repository_set_index,
	const Resource& repo,
	const Resource& index);

#endif

