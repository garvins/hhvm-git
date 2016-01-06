/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_DIFF_H
#define HHVM_GIT2_DIFF_H


using namespace HPHP;

void HHVM_FUNCTION(git_diff_free,
	const Resource& diff);

/* todo
int64_t HHVM_FUNCTION(git_diff_tree_to_tree,
	const Resource& repo,
	const Resource& old_tree,
	const Resource& new_tree,
	const Resource& opts);

int64_t HHVM_FUNCTION(git_diff_tree_to_index,
    const Resource& repo,
	const Resource& old_tree,
	const Resource& index,
	const Resource& opts);

int64_t HHVM_FUNCTION(git_diff_index_to_workdir,
    const Resource& repo,
	const Resource& index,
	const Resource& opts);

int64_t HHVM_FUNCTION(git_diff_tree_to_workdir,
	const Resource& repo,
	const Resource& old_tree,
	const Resource& opts);

int64_t HHVM_FUNCTION(git_diff_tree_to_workdir_with_index,
	const Resource& repo,
	const Resource& old_tree,
	const Resource& opts); */

int64_t HHVM_FUNCTION(git_diff_merge,
	const Resource& onto,
	const Resource& from);

int64_t HHVM_FUNCTION(git_diff_find_similar,
	const Resource& diff,
	const Resource& options);

int64_t HHVM_FUNCTION(git_diff_options_init,
	const Resource& options,
	int64_t version);

int64_t HHVM_FUNCTION(git_diff_num_deltas,
	const Resource& diff);

int64_t HHVM_FUNCTION(git_diff_num_deltas_of_type,
	const Resource& diff,
	int64_t type);

Resource HHVM_FUNCTION(git_diff_get_delta,
	const Resource& diff,
	int64_t idx);

int64_t HHVM_FUNCTION(git_diff_is_sorted_icase,
	const Resource& diff);

int64_t HHVM_FUNCTION(git_diff_foreach,
	const Resource& diff,
	const Variant& file_cb,
	const Variant& hunk_cb,
	const Variant& line_cb,
	const Variant& payload);

String HHVM_FUNCTION(git_diff_status_char,
	int64_t status);

int64_t HHVM_FUNCTION(git_diff_print,
	const Resource& diff,
	int64_t format,
	const Variant& print_cb,
	const Variant& payload);

int64_t HHVM_FUNCTION(git_diff_blobs,
	const Resource& old_blob,
	const String& old_as_path,
	const Resource& new_blob,
	const String& new_as_path,
	const Resource& options,
	const Variant& file_cb,
	const Variant& hunk_cb,
	const Variant& line_cb,
	const Variant& payload);

int64_t HHVM_FUNCTION(git_diff_blob_to_buffer,
	const Resource& old_blob,
	const String& old_as_path,
	const String& buffer,
	int64_t buffer_len,
	const String& buffer_as_path,
	const Resource& options,
	const Variant& file_cb,
	const Variant& hunk_cb,
	const Variant& line_cb,
	const Variant& payload);

#endif

