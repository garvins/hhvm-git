/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_COMMIT_H
#define HHVM_GIT2_COMMIT_H

#include "../ext_git2.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_commit_lookup,
	const Resource& repo,
	const String& id);

Resource HHVM_FUNCTION(git_commit_lookup_prefix,
	const Resource& repo,
	const String& id,
	int64_t len);

void HHVM_FUNCTION(git_commit_free,
	const Resource& commit);

String HHVM_FUNCTION(git_commit_id,
	const Resource& commit);

Resource HHVM_FUNCTION(git_commit_owner,
	const Resource& commit);

String HHVM_FUNCTION(git_commit_message_encoding,
	const Resource& commit);

String HHVM_FUNCTION(git_commit_message,
	const Resource& commit);

String HHVM_FUNCTION(git_commit_message_raw,
	const Resource& commit);

int64_t HHVM_FUNCTION(git_commit_time,
	const Resource& commit);

int64_t HHVM_FUNCTION(git_commit_time_offset,
	const Resource& commit);

Resource HHVM_FUNCTION(git_commit_committer,
	const Resource& commit);

Array HHVM_FUNCTION(git_commit_author,
	const Resource& commit);

String HHVM_FUNCTION(git_commit_raw_header,
	const Resource& commit);

Resource HHVM_FUNCTION(git_commit_tree,
	const Resource& commit);

String HHVM_FUNCTION(git_commit_tree_id,
	const Resource& commit);

int64_t HHVM_FUNCTION(git_commit_parentcount,
	const Resource& commit);

Resource HHVM_FUNCTION(git_commit_parent,
	const Resource& commit,
	int64_t n);

String HHVM_FUNCTION(git_commit_parent_id,
	const Resource& commit,
	int64_t n);

Resource HHVM_FUNCTION(git_commit_nth_gen_ancestor,
	const Resource& commit,
	int64_t n);

String HHVM_FUNCTION(git_commit_create,
	const Resource& repo,
	const String& update_ref,
	const Array& author,
	const Array& committer,
	const String& message_encoding,
	const String& message,
	const Resource& tree,
	int64_t parent_count,
	const Array& parents);

String HHVM_FUNCTION(git_commit_create_v,
	const Resource& repo,
	const String& update_ref,
	const Resource& author,
	const Resource& committer,
	const String& message_encoding,
	const String& message,
	const Resource& tree,
	int64_t parent_count);

#endif

