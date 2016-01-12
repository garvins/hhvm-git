/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_INDEX_H
#define HHVM_GIT2_INDEX_H

#include "../ext_git2.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_index_open,
	const String& index_path);

Resource HHVM_FUNCTION(git_index_new);

void HHVM_FUNCTION(git_index_free,
	const Resource& index);

Resource HHVM_FUNCTION(git_index_owner,
	const Resource& index);

int64_t HHVM_FUNCTION(git_index_caps,
	const Resource& index);

int64_t HHVM_FUNCTION(git_index_set_caps,
	const Resource& index,
	int64_t caps);

int64_t HHVM_FUNCTION(git_index_read,
	const Resource& index,
	int64_t force);

int64_t HHVM_FUNCTION(git_index_write,
	const Resource& index);

String HHVM_FUNCTION(git_index_path,
	const Resource& index);

int64_t HHVM_FUNCTION(git_index_read_tree,
	const Resource& index,
	const Resource& tree);

String HHVM_FUNCTION(git_index_write_tree,
	const Resource& index);

String HHVM_FUNCTION(git_index_write_tree_to,
	const Resource& index,
	const Resource& repo);

int64_t HHVM_FUNCTION(git_index_entrycount,
	const Resource& index);

void HHVM_FUNCTION(git_index_clear,
	const Resource& index);

Resource HHVM_FUNCTION(git_index_get_byindex,
	const Resource& index,
	int64_t n);

Resource HHVM_FUNCTION(git_index_get_bypath,
	const Resource& index,
	const String& path,
	int64_t stage);

int64_t HHVM_FUNCTION(git_index_remove,
	const Resource& index,
	const String& path,
	int64_t stage);

int64_t HHVM_FUNCTION(git_index_remove_directory,
	const Resource& index,
	const String& dir,
	int64_t stage);

int64_t HHVM_FUNCTION(git_index_add,
	const Resource& index,
	const Array& source_entry);

int64_t HHVM_FUNCTION(git_index_entry_stage,
	const Resource& entry);

int64_t HHVM_FUNCTION(git_index_add_bypath,
	const Resource& index,
	const String& path);

int64_t HHVM_FUNCTION(git_index_remove_bypath,
	const Resource& index,
	const String& path);

int64_t HHVM_FUNCTION(git_index_add_all,
	const Resource& index,
	const Resource& pathspec,
	int64_t flags,
	const Variant& callback,
	const Variant& payload);

int64_t HHVM_FUNCTION(git_index_remove_all,
	const Resource& index,
	const Resource& pathspec,
	const Variant& callback,
	const Variant& payload);

int64_t HHVM_FUNCTION(git_index_update_all,
	const Resource& index,
	const Resource& pathspec,
	const Variant& callback,
	const Variant& payload);

int64_t HHVM_FUNCTION(git_index_find,
	int64_t at_pos,
	const Resource& index,
	const String& path);

int64_t HHVM_FUNCTION(git_index_conflict_add,
	const Resource& index,
	const Resource& ancestor_entry,
	const Resource& our_entry,
	const Resource& their_entry);

Array HHVM_FUNCTION(git_index_conflict_get,
	const Resource& index,
	const String& path);

int64_t HHVM_FUNCTION(git_index_conflict_remove,
	const Resource& index,
	const String& path);

void HHVM_FUNCTION(git_index_conflict_cleanup,
	const Resource& index);

int64_t HHVM_FUNCTION(git_index_has_conflicts,
	const Resource& index);

Resource HHVM_FUNCTION(git_index_conflict_iterator_new,
	const Resource& index);

Array HHVM_FUNCTION(git_index_conflict_next,
	const Resource& iterator);

void HHVM_FUNCTION(git_index_conflict_iterator_free,
	const Resource& iterator);

#endif

