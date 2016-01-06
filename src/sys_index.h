/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_SYS_INDEX_H
#define HHVM_GIT2_SYS_INDEX_H


using namespace HPHP;

int64_t HHVM_FUNCTION(git_index_name_entrycount,
	const Resource& index);

Resource HHVM_FUNCTION(git_index_name_get_byindex,
	const Resource& index,
	int64_t n);

int64_t HHVM_FUNCTION(git_index_name_add,
	const Resource& index,
	const String& ancestor,
	const String& ours,
	const String& theirs);

void HHVM_FUNCTION(git_index_name_clear,
	const Resource& index);

int64_t HHVM_FUNCTION(git_index_reuc_entrycount,
	const Resource& index);

int64_t HHVM_FUNCTION(git_index_reuc_find,
	int64_t at_pos,
	const Resource& index,
	const String& path);

Resource HHVM_FUNCTION(git_index_reuc_get_bypath,
	const Resource& index,
	const String& path);

Resource HHVM_FUNCTION(git_index_reuc_get_byindex,
	const Resource& index,
	int64_t n);

int64_t HHVM_FUNCTION(git_index_reuc_add,
	const Resource& index,
	const String& path,
	int64_t ancestor_mode,
	const String& ancestor_id,
	int64_t our_mode,
	const String& our_id,
	int64_t their_mode,
	const String& their_id);

int64_t HHVM_FUNCTION(git_index_reuc_remove,
	const Resource& index,
	int64_t n);

void HHVM_FUNCTION(git_index_reuc_clear,
	const Resource& index);

#endif

