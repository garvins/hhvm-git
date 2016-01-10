/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_BRANCH_H
#define HHVM_GIT2_BRANCH_H

#include "../ext_git2.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_branch_create,
	const Resource& repo,
	const String& branch_name,
	const Resource& target,
	int64_t force);

int64_t HHVM_FUNCTION(git_branch_delete,
	const Resource& branch);

Resource HHVM_FUNCTION(git_branch_iterator_new,
	const Resource& repo,
	int64_t list_flags);

Resource HHVM_FUNCTION(git_branch_next,
	int64_t out_type,
	const Resource& iter);

void HHVM_FUNCTION(git_branch_iterator_free,
	const Resource& iter);

Resource HHVM_FUNCTION(git_branch_move,
	const Resource& branch,
	const String& new_branch_name,
	int64_t force);

Resource HHVM_FUNCTION(git_branch_lookup,
	const Resource& repo,
	const String& branch_name,
	int64_t branch_type);

String HHVM_FUNCTION(git_branch_name,
	const Resource& ref);

Resource HHVM_FUNCTION(git_branch_upstream,
	const Resource& branch);

int64_t HHVM_FUNCTION(git_branch_set_upstream,
	const Resource& branch,
	const String& upstream_name);

String HHVM_FUNCTION(git_branch_upstream_name,
	int64_t buffer_size,
	const Resource& repo,
	const String& canonical_branch_name);

int64_t HHVM_FUNCTION(git_branch_is_head,
	const Resource& branch);

String HHVM_FUNCTION(git_branch_remote_name,
	int64_t buffer_size,
	const Resource& repo,
	const String& canonical_branch_name);

#endif

