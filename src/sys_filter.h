/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_SYS_FILTER_H
#define HHVM_GIT2_SYS_FILTER_H


using namespace HPHP;

Resource HHVM_FUNCTION(git_filter_lookup,
	const String& name);

Resource HHVM_FUNCTION(git_filter_list_new,
	const Resource& repo,
	int64_t mode);

int64_t HHVM_FUNCTION(git_filter_list_push,
	const Resource& fl,
	const Resource& filter,
	const Variant& payload);

int64_t HHVM_FUNCTION(git_filter_list_length,
	const Resource& fl);

Resource HHVM_FUNCTION(git_filter_source_repo,
	const Resource& src);

String HHVM_FUNCTION(git_filter_source_path,
	const Resource& src);

int64_t HHVM_FUNCTION(git_filter_source_filemode,
	const Resource& src);

String HHVM_FUNCTION(git_filter_source_id,
	const Resource& src);

int64_t HHVM_FUNCTION(git_filter_source_mode,
	const Resource& src);

int64_t HHVM_FUNCTION(git_filter_register,
	const String& name,
	const Resource& filter,
	int64_t priority);

int64_t HHVM_FUNCTION(git_filter_unregister,
	const String& name);

#endif

