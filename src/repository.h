/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_REPOSITORY_H
#define HHVM_GIT2_REPOSITORY_H

#include "../ext_git2.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_repository_open,
	const String& path);

Resource HHVM_FUNCTION(git_repository_wrap_odb,
	const Resource& odb);

String HHVM_FUNCTION(git_repository_discover,
	int64_t path_size,
	const String& start_path,
	int64_t across_fs,
	const String& ceiling_dirs);

Resource HHVM_FUNCTION(git_repository_open_ext,
	const String& path,
	int64_t flags,
	const String& ceiling_dirs);

Resource HHVM_FUNCTION(git_repository_open_bare,
	const String& bare_path);

void HHVM_FUNCTION(git_repository_free,
	const Resource& repo);

Resource HHVM_FUNCTION(git_repository_init,
	const String& path,
	int64_t is_bare);

Resource HHVM_FUNCTION(git_repository_init_ext,
	const String& repo_path,
	const Array& opts = null_array);

Resource HHVM_FUNCTION(git_repository_head,
	const Resource& repo);

int64_t HHVM_FUNCTION(git_repository_head_detached,
	const Resource& repo);

int64_t HHVM_FUNCTION(git_repository_head_unborn,
	const Resource& repo);

int64_t HHVM_FUNCTION(git_repository_is_empty,
	const Resource& repo);

String HHVM_FUNCTION(git_repository_path,
	const Resource& repo);

String HHVM_FUNCTION(git_repository_workdir,
	const Resource& repo);

int64_t HHVM_FUNCTION(git_repository_set_workdir,
	const Resource& repo,
	const String& workdir,
	int64_t update_gitlink);

int64_t HHVM_FUNCTION(git_repository_is_bare,
	const Resource& repo);

Resource HHVM_FUNCTION(git_repository_config,
	const Resource& repo);

Resource HHVM_FUNCTION(git_repository_odb,
	const Resource& repo);

Resource HHVM_FUNCTION(git_repository_refdb,
	const Resource& repo);

Resource HHVM_FUNCTION(git_repository_index,
	const Resource& repo);

String HHVM_FUNCTION(git_repository_message,
	int64_t len,
	const Resource& repo);

int64_t HHVM_FUNCTION(git_repository_message_remove,
	const Resource& repo);

int64_t HHVM_FUNCTION(git_repository_merge_cleanup,
	const Resource& repo);

int64_t HHVM_FUNCTION(git_repository_fetchhead_foreach,
	const Resource& repo,
	const Variant& callback,
	const Variant& payload);

int64_t HHVM_FUNCTION(git_repository_mergehead_foreach,
	const Resource& repo,
	const Variant& callback,
	const Variant& payload);

String HHVM_FUNCTION(git_repository_hashfile,
	const Resource& repo,
	const String& path,
	int64_t type,
	const String& as_path);

int64_t HHVM_FUNCTION(git_repository_set_head,
	const Resource& repo,
	const String& refname);

int64_t HHVM_FUNCTION(git_repository_set_head_detached,
	const Resource& repo,
	const String& commitish);

int64_t HHVM_FUNCTION(git_repository_detach_head,
	const Resource& repo);

int64_t HHVM_FUNCTION(git_repository_state,
	const Resource& repo);

int64_t HHVM_FUNCTION(git_repository_set_namespace,
	const Resource& repo,
	const String& nmspace);

String HHVM_FUNCTION(git_repository_get_namespace,
	const Resource& repo);

int64_t HHVM_FUNCTION(git_repository_is_shallow,
	const Resource& repo);

#endif

