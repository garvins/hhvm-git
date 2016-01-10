/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_REVWALK_H
#define HHVM_GIT2_REVWALK_H

#include "../ext_git2.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_revwalk_new,
	const Resource& repo);

void HHVM_FUNCTION(git_revwalk_reset,
	const Resource& walker);

int64_t HHVM_FUNCTION(git_revwalk_push,
	const Resource& walk,
	const String& id);

int64_t HHVM_FUNCTION(git_revwalk_push_glob,
	const Resource& walk,
	const String& glob);

int64_t HHVM_FUNCTION(git_revwalk_push_head,
	const Resource& walk);

int64_t HHVM_FUNCTION(git_revwalk_hide,
	const Resource& walk,
	const String& commit_id);

int64_t HHVM_FUNCTION(git_revwalk_hide_glob,
	const Resource& walk,
	const String& glob);

int64_t HHVM_FUNCTION(git_revwalk_hide_head,
	const Resource& walk);

int64_t HHVM_FUNCTION(git_revwalk_push_ref,
	const Resource& walk,
	const String& refname);

int64_t HHVM_FUNCTION(git_revwalk_hide_ref,
	const Resource& walk,
	const String& refname);

String HHVM_FUNCTION(git_revwalk_next,
	const Resource& walk);

void HHVM_FUNCTION(git_revwalk_sorting,
	const Resource& walk,
	int64_t sort_mode);

int64_t HHVM_FUNCTION(git_revwalk_push_range,
	const Resource& walk,
	const String& range);

void HHVM_FUNCTION(git_revwalk_simplify_first_parent,
	const Resource& walk);

void HHVM_FUNCTION(git_revwalk_free,
	const Resource& walk);

Resource HHVM_FUNCTION(git_revwalk_repository,
	const Resource& walk);

#endif

