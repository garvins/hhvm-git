/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_TREE_H
#define HHVM_GIT2_TREE_H


using namespace HPHP;

Resource HHVM_FUNCTION(git_tree_lookup,
	const Resource& repo,
	const String& id);

Resource HHVM_FUNCTION(git_tree_lookup_prefix,
	const Resource& repo,
	const String& id,
	int64_t len);

void HHVM_FUNCTION(git_tree_free,
	const Resource& tree);

String HHVM_FUNCTION(git_tree_id,
	const Resource& tree);

Resource HHVM_FUNCTION(git_tree_owner,
	const Resource& tree);

int64_t HHVM_FUNCTION(git_tree_entrycount,
	const Resource& tree);

Resource HHVM_FUNCTION(git_tree_entry_byname,
	const Resource& tree,
	const String& filename);

Resource HHVM_FUNCTION(git_tree_entry_byindex,
	const Resource& tree,
	int64_t idx);

Resource HHVM_FUNCTION(git_tree_entry_byoid,
	const Resource& tree,
	const String& oid);

Resource HHVM_FUNCTION(git_tree_entry_bypath,
	const Resource& root,
	const String& path);

Resource HHVM_FUNCTION(git_tree_entry_dup,
	const Resource& entry);

void HHVM_FUNCTION(git_tree_entry_free,
	const Resource& entry);

String HHVM_FUNCTION(git_tree_entry_name,
	const Resource& entry);

String HHVM_FUNCTION(git_tree_entry_id,
	const Resource& entry);

int64_t HHVM_FUNCTION(git_tree_entry_type,
	const Resource& entry);

int64_t HHVM_FUNCTION(git_tree_entry_filemode,
	const Resource& entry);

int64_t HHVM_FUNCTION(git_tree_entry_filemode_raw,
	const Resource& entry);

int64_t HHVM_FUNCTION(git_tree_entry_cmp,
	const Resource& e1,
	const Resource& e2);

Resource HHVM_FUNCTION(git_tree_entry_to_object,
	const Resource& repo,
	const Resource& entry);

Resource HHVM_FUNCTION(git_treebuilder_create,
	const Resource& source);

void HHVM_FUNCTION(git_treebuilder_clear,
	const Resource& bld);

int64_t HHVM_FUNCTION(git_treebuilder_entrycount,
	const Resource& bld);

void HHVM_FUNCTION(git_treebuilder_free,
	const Resource& bld);

Resource HHVM_FUNCTION(git_treebuilder_get,
	const Resource& bld,
	const String& filename);

Resource HHVM_FUNCTION(git_treebuilder_insert,
	const Resource& bld,
	const String& filename,
	const String& id,
	int64_t filemode);

int64_t HHVM_FUNCTION(git_treebuilder_remove,
	const Resource& bld,
	const String& filename);

void HHVM_FUNCTION(git_treebuilder_filter,
	const Resource& bld,
	const Variant& filter,
	const Variant& payload);

int64_t HHVM_FUNCTION(git_treebuilder_write,
	const String& id,
	const Resource& repo,
	const Resource& bld);

int64_t HHVM_FUNCTION(git_tree_walk,
	const Resource& tree,
	int64_t mode,
	const Variant& callback,
	const Variant& payload);

#endif

