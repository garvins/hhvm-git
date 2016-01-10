/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_MERGE_H
#define HHVM_GIT2_MERGE_H

#include "../ext_git2.h"

using namespace HPHP;

String HHVM_FUNCTION(git_merge_base,
	const Resource& repo,
	const String& one,
	const String& two);

String HHVM_FUNCTION(git_merge_base_many,
	const Resource& repo,
	int64_t length,
	const String& input_array);

Resource HHVM_FUNCTION(git_merge_head_from_ref,
	const Resource& repo,
	const Resource& ref);

Resource HHVM_FUNCTION(git_merge_head_from_fetchhead,
	const Resource& repo,
	const String& branch_name,
	const String& remote_url,
	const String& oid);

Resource HHVM_FUNCTION(git_merge_head_from_oid,
	const Resource& repo,
	const String& oid);

void HHVM_FUNCTION(git_merge_head_free,
	const Resource& head);

Resource HHVM_FUNCTION(git_merge_trees,
	const Resource& repo,
	const Resource& ancestor_tree,
	const Resource& our_tree,
	const Resource& their_tree,
	const Resource& opts);

Resource HHVM_FUNCTION(git_merge,
	const Resource& repo,
	const Resource& their_heads,
	const Resource& opts);

int64_t HHVM_FUNCTION(git_merge_result_is_uptodate,
	const Resource& merge_result);

int64_t HHVM_FUNCTION(git_merge_result_is_fastforward,
	const Resource& merge_result);

String HHVM_FUNCTION(git_merge_result_fastforward_oid,
	const Resource& merge_result);

void HHVM_FUNCTION(git_merge_result_free,
	const Resource& merge_result);

#endif

