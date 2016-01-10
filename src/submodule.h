/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_SUBMODULE_H
#define HHVM_GIT2_SUBMODULE_H

#include "../ext_git2.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_submodule_lookup,
	const Resource& repo,
	const String& name);

int64_t HHVM_FUNCTION(git_submodule_foreach,
	const Resource& repo,
	int64_t cb,
	const Variant& payload);

Resource HHVM_FUNCTION(git_submodule_add_setup,
	const Resource& repo,
	const String& url,
	const String& path,
	int64_t use_gitlink);

int64_t HHVM_FUNCTION(git_submodule_add_finalize,
	const Resource& submodule);

int64_t HHVM_FUNCTION(git_submodule_add_to_index,
	const Resource& submodule,
	int64_t write_index);

int64_t HHVM_FUNCTION(git_submodule_save,
	const Resource& submodule);

Resource HHVM_FUNCTION(git_submodule_owner,
	const Resource& submodule);

String HHVM_FUNCTION(git_submodule_name,
	const Resource& submodule);

String HHVM_FUNCTION(git_submodule_path,
	const Resource& submodule);

String HHVM_FUNCTION(git_submodule_url,
	const Resource& submodule);

int64_t HHVM_FUNCTION(git_submodule_set_url,
	const Resource& submodule,
	const String& url);

String HHVM_FUNCTION(git_submodule_index_id,
	const Resource& submodule);

String HHVM_FUNCTION(git_submodule_head_id,
	const Resource& submodule);

String HHVM_FUNCTION(git_submodule_wd_id,
	const Resource& submodule);

int64_t HHVM_FUNCTION(git_submodule_ignore,
	const Resource& submodule);

int64_t HHVM_FUNCTION(git_submodule_set_ignore,
	const Resource& submodule,
	int64_t ignore);

int64_t HHVM_FUNCTION(git_submodule_update,
	const Resource& submodule);

int64_t HHVM_FUNCTION(git_submodule_set_update,
	const Resource& submodule,
	int64_t update);

int64_t HHVM_FUNCTION(git_submodule_fetch_recurse_submodules,
	const Resource& submodule);

int64_t HHVM_FUNCTION(git_submodule_set_fetch_recurse_submodules,
	const Resource& submodule,
	int64_t fetch_recurse_submodules);

int64_t HHVM_FUNCTION(git_submodule_init,
	const Resource& submodule,
	int64_t overwrite);

int64_t HHVM_FUNCTION(git_submodule_sync,
	const Resource& submodule);

Resource HHVM_FUNCTION(git_submodule_open,
	const Resource& submodule);

int64_t HHVM_FUNCTION(git_submodule_reload,
	const Resource& submodule);

int64_t HHVM_FUNCTION(git_submodule_reload_all,
	const Resource& repo);

int64_t HHVM_FUNCTION(git_submodule_status,
	int64_t status,
	const Resource& submodule);

int64_t HHVM_FUNCTION(git_submodule_location,
	int64_t location_status,
	const Resource& submodule);

#endif

