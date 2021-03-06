/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_BLOB_H
#define HHVM_GIT2_BLOB_H

#include "../ext_git2.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_blob_lookup,
	const Resource& repo,
	const String& id);

Resource HHVM_FUNCTION(git_blob_lookup_prefix,
	const Resource& repo,
	const String& id,
	int64_t len);

void HHVM_FUNCTION(git_blob_free,
	const Resource& blob);

String HHVM_FUNCTION(git_blob_id,
	const Resource& blob);

Resource HHVM_FUNCTION(git_blob_owner,
	const Resource& blob);

String HHVM_FUNCTION(git_blob_rawcontent,
	const Resource& blob);

int64_t HHVM_FUNCTION(git_blob_rawsize,
	const Resource& blob);

Resource HHVM_FUNCTION(git_blob_filtered_content,
	const Resource& blob,
	const String& as_path,
	int64_t check_for_binary_data);

String HHVM_FUNCTION(git_blob_create_fromworkdir,
	const Resource& repo,
	const String& relative_path);

String HHVM_FUNCTION(git_blob_create_fromdisk,
	const Resource& repo,
	const String& path);

String HHVM_FUNCTION(git_blob_create_fromchunks,
	const Resource& repo,
	const String& hintpath,
	const Variant& callback,
	const Variant& payload);

String HHVM_FUNCTION(git_blob_create_frombuffer,
	const Resource& repo,
	const Variant& buffer,
	int64_t len);

int64_t HHVM_FUNCTION(git_blob_is_binary,
	const Resource& blob);

#endif

