/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_PATCH_H
#define HHVM_GIT2_PATCH_H


using namespace HPHP;

Resource HHVM_FUNCTION(git_patch_from_diff,
	const Resource& diff,
	int64_t idx);

Resource HHVM_FUNCTION(git_patch_from_blobs,
	const Resource& old_blob,
	const String& old_as_path,
	const Resource& new_blob,
	const String& new_as_path,
	const Resource& opts);

Resource HHVM_FUNCTION(git_patch_from_blob_and_buffer,
	const Resource& old_blob,
	const String& old_as_path,
	const String& buffer,
	int64_t buffer_len,
	const String& buffer_as_path,
	const Resource& opts);

void HHVM_FUNCTION(git_patch_free,
	const Resource& patch);

Resource HHVM_FUNCTION(git_patch_get_delta,
	const Resource& patch);

int64_t HHVM_FUNCTION(git_patch_num_hunks,
	const Resource& patch);

int64_t HHVM_FUNCTION(git_patch_line_stats,
	const Resource& patch);

Resource HHVM_FUNCTION(git_patch_get_hunk,
	int64_t lines_in_hunk,
	const Resource& patch,
	int64_t hunk_idx);

int64_t HHVM_FUNCTION(git_patch_num_lines_in_hunk,
	const Resource& patch,
	int64_t hunk_idx);

Resource HHVM_FUNCTION(git_patch_get_line_in_hunk,
	const Resource& patch,
	int64_t hunk_idx,
	int64_t line_of_hunk);

int64_t HHVM_FUNCTION(git_patch_size,
	const Resource& patch,
	int64_t include_context,
	int64_t include_hunk_headers,
	int64_t include_file_headers);

int64_t HHVM_FUNCTION(git_patch_print,
	const Resource& patch,
	const Variant& print_cb,
	const Variant& payload);

int64_t HHVM_FUNCTION(git_patch_to_str,
	const Array& string,
	const Resource& patch);

#endif

