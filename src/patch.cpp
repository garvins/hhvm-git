/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/system/systemlib.h"

#include "patch.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_patch_from_diff,
	const Resource& diff,
	int64_t idx)
{
	auto return_value = req::make<Git2Resource>();

	git_patch *out = NULL;

	auto diff_ = dyn_cast<Git2Resource>(diff);

	git_patch_from_diff(&out, HHVM_GIT2_V(diff_, diff), (size_t) idx);
	HHVM_GIT2_V(return_value, patch) = out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_patch_from_blobs,
	const Resource& old_blob,
	const String& old_as_path,
	const Resource& new_blob,
	const String& new_as_path,
	const Resource& opts)
{
	auto return_value = req::make<Git2Resource>();

	git_patch *out = NULL;

	auto old_blob_ = dyn_cast<Git2Resource>(old_blob);
	auto new_blob_ = dyn_cast<Git2Resource>(new_blob);
	auto opts_ = dyn_cast<Git2Resource>(opts);

	git_patch_from_blobs(&out, HHVM_GIT2_V(old_blob_, blob), old_as_path.c_str(), HHVM_GIT2_V(new_blob_, blob), new_as_path.c_str(), HHVM_GIT2_V(opts_, diff_options));
	HHVM_GIT2_V(return_value, patch) = out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_patch_from_blob_and_buffer,
	const Resource& old_blob,
	const String& old_as_path,
	const String& buffer,
	int64_t buffer_len,
	const String& buffer_as_path,
	const Resource& opts)
{
	auto return_value = req::make<Git2Resource>();

	git_patch *out = NULL;

	auto old_blob_ = dyn_cast<Git2Resource>(old_blob);
	auto opts_ = dyn_cast<Git2Resource>(opts);

	git_patch_from_blob_and_buffer(&out, HHVM_GIT2_V(old_blob_, blob), old_as_path.c_str(), buffer.c_str(), (size_t) buffer_len, buffer_as_path.c_str(), HHVM_GIT2_V(opts_, diff_options));
	HHVM_GIT2_V(return_value, patch) = out;
	return Resource(return_value);
}

void HHVM_FUNCTION(git_patch_free,
	const Resource& patch)
{

	auto patch_ = dyn_cast<Git2Resource>(patch);

	git_patch_free(HHVM_GIT2_V(patch_, patch));
}

Resource HHVM_FUNCTION(git_patch_get_delta,
	const Resource& patch)
{
	const git_diff_delta *result;
	auto return_value = req::make<Git2Resource>();

	auto patch_ = dyn_cast<Git2Resource>(patch);

	result = git_patch_get_delta(HHVM_GIT2_V(patch_, patch));
	//HHVM_GIT2_V(return_value, diff_delta) = result; todo return as array
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_patch_num_hunks,
	const Resource& patch)
{
	size_t result;
	int64_t return_value;

	auto patch_ = dyn_cast<Git2Resource>(patch);

	result = git_patch_num_hunks(HHVM_GIT2_V(patch_, patch));
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_patch_line_stats,
	const Resource& patch)
{
	int result;
	int64_t return_value;
    size_t *total_context = 0, *total_additions = 0, *total_deletions = 0;

	auto patch_ = dyn_cast<Git2Resource>(patch);

    // todo return total_context, total_additions and total_deletions as array
	result = git_patch_line_stats( total_context, total_additions, total_deletions, HHVM_GIT2_V(patch_, patch));
	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_patch_get_hunk,
	int64_t lines_in_hunk,
	const Resource& patch,
	int64_t hunk_idx)
{
	auto return_value = req::make<Git2Resource>();

	const git_diff_hunk *out = NULL;

	auto patch_ = dyn_cast<Git2Resource>(patch);

	git_patch_get_hunk(&out, (size_t*) lines_in_hunk, HHVM_GIT2_V(patch_, patch), (size_t) hunk_idx);
	//HHVM_GIT2_V(return_value, diff_hunk) = out; todo return as array
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_patch_num_lines_in_hunk,
	const Resource& patch,
	int64_t hunk_idx)
{
	int result;
	int64_t return_value;

	auto patch_ = dyn_cast<Git2Resource>(patch);

	result = git_patch_num_lines_in_hunk(HHVM_GIT2_V(patch_, patch), (size_t) hunk_idx);
	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_patch_get_line_in_hunk,
	const Resource& patch,
	int64_t hunk_idx,
	int64_t line_of_hunk)
{
	auto return_value = req::make<Git2Resource>();

	const git_diff_line *out = NULL;

	auto patch_ = dyn_cast<Git2Resource>(patch);

	git_patch_get_line_in_hunk(&out, HHVM_GIT2_V(patch_, patch), (size_t) hunk_idx, (size_t) line_of_hunk);
	//HHVM_GIT2_V(return_value, diff_line) = out; todo return as array
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_patch_size,
	const Resource& patch,
	int64_t include_context,
	int64_t include_hunk_headers,
	int64_t include_file_headers)
{
	size_t result;
	int64_t return_value;

	auto patch_ = dyn_cast<Git2Resource>(patch);

	result = git_patch_size(HHVM_GIT2_V(patch_, patch), (int) include_context, (int) include_hunk_headers, (int) include_file_headers);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_patch_print,
	const Resource& patch,
	const Variant& print_cb,
	const Variant& payload)
{
	int result;
	int64_t return_value;

	git_diff_line_cb print_cb_ = NULL;
	void *payload_ = NULL;

	auto patch_ = dyn_cast<Git2Resource>(patch);
	print_cb_ = NULL;

	result = git_patch_print(HHVM_GIT2_V(patch_, patch), /* todo */ print_cb_, payload_);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_patch_to_str,
	const Array& string,
	const Resource& patch)
{
	int result;
	int64_t return_value;

	char **string_;

	auto patch_ = dyn_cast<Git2Resource>(patch);

	result = git_patch_to_str(string_, HHVM_GIT2_V(patch_, patch));
	return_value = (int64_t) result;
	return return_value;
}

