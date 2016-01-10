/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_PATHSPEC_H
#define HHVM_GIT2_PATHSPEC_H

#include "../ext_git2.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_pathspec_new,
	const Resource& pathspec);

void HHVM_FUNCTION(git_pathspec_free,
	const Resource& ps);

int64_t HHVM_FUNCTION(git_pathspec_matches_path,
	const Resource& ps,
	int64_t flags,
	const String& path);

Resource HHVM_FUNCTION(git_pathspec_match_workdir,
	const Resource& repo,
	int64_t flags,
	const Resource& ps);

Resource HHVM_FUNCTION(git_pathspec_match_index,
	const Resource& index,
	int64_t flags,
	const Resource& ps);

Resource HHVM_FUNCTION(git_pathspec_match_tree,
	const Resource& tree,
	int64_t flags,
	const Resource& ps);

Resource HHVM_FUNCTION(git_pathspec_match_diff,
	const Resource& diff,
	int64_t flags,
	const Resource& ps);

void HHVM_FUNCTION(git_pathspec_match_list_free,
	const Resource& m);

int64_t HHVM_FUNCTION(git_pathspec_match_list_entrycount,
	const Resource& m);

String HHVM_FUNCTION(git_pathspec_match_list_entry,
	const Resource& m,
	int64_t pos);

Resource HHVM_FUNCTION(git_pathspec_match_list_diff_entry,
	const Resource& m,
	int64_t pos);

int64_t HHVM_FUNCTION(git_pathspec_match_list_failed_entrycount,
	const Resource& m);

String HHVM_FUNCTION(git_pathspec_match_list_failed_entry,
	const Resource& m,
	int64_t pos);

#endif

