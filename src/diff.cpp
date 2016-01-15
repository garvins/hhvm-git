/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "diff.h"

using namespace HPHP;

void HHVM_FUNCTION(git_diff_free,
	const Resource& diff)
{

	auto diff_ = dyn_cast<Git2Resource>(diff);

	git_diff_free(HHVM_GIT2_V(diff_, diff));
}

Resource HHVM_FUNCTION(git_diff_tree_to_tree,
	const Resource& repo,
	const Resource& old_tree,
	const Resource& new_tree,
	const Array& opts)
{
	auto return_value = req::make<Git2Resource>();

	git_diff *diff = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto old_tree_ = dyn_cast<Git2Resource>(old_tree);
	auto new_tree_ = dyn_cast<Git2Resource>(new_tree);

	git_diff_tree_to_tree(&diff, HHVM_GIT2_V(repo_, repository), HHVM_GIT2_V(old_tree_, tree), HHVM_GIT2_V(new_tree_, tree), NULL);
	HHVM_GIT2_V(return_value, diff) = diff;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_diff_tree_to_index,
	const Resource& repo,
	const Resource& old_tree,
	const Resource& index,
	const Array& opts)
{
	auto return_value = req::make<Git2Resource>();

	git_diff *diff = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto old_tree_ = dyn_cast<Git2Resource>(old_tree);
	auto index_ = dyn_cast<Git2Resource>(index);

	git_diff_tree_to_index(&diff, HHVM_GIT2_V(repo_, repository), HHVM_GIT2_V(old_tree_, tree), HHVM_GIT2_V(index_, index), NULL);
	HHVM_GIT2_V(return_value, diff) = diff;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_diff_index_to_workdir,
	const Resource& repo,
	const Resource& index,
	const Resource& opts)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_diff *diff = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto index_ = dyn_cast<Git2Resource>(index);
	auto opts_ = dyn_cast<Git2Resource>(opts);

	result = git_diff_index_to_workdir(&diff, HHVM_GIT2_V(repo_, repository), HHVM_GIT2_V(index_, index), HHVM_GIT2_V(opts_, diff_options));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, diff) = diff;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_diff_tree_to_workdir,
	const Resource& repo,
	const Resource& old_tree,
	const Resource& opts)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_diff *diff = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto old_tree_ = dyn_cast<Git2Resource>(old_tree);
	auto opts_ = dyn_cast<Git2Resource>(opts);

	result = git_diff_tree_to_workdir(&diff, HHVM_GIT2_V(repo_, repository), HHVM_GIT2_V(old_tree_, tree), HHVM_GIT2_V(opts_, diff_options));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, diff) = diff;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_diff_tree_to_workdir_with_index,
	const Resource& repo,
	const Resource& old_tree,
	const Array& opts)
{
	auto return_value = req::make<Git2Resource>();

	git_diff *diff = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto old_tree_ = dyn_cast<Git2Resource>(old_tree);

	git_diff_tree_to_workdir_with_index(&diff, HHVM_GIT2_V(repo_, repository), HHVM_GIT2_V(old_tree_, tree), NULL);
	HHVM_GIT2_V(return_value, diff) = diff;
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_diff_merge,
	const Resource& onto,
	const Resource& from)
{
	int result;
	int64_t return_value;

	auto onto_ = dyn_cast<Git2Resource>(onto);
	auto from_ = dyn_cast<Git2Resource>(from);

	result = git_diff_merge(HHVM_GIT2_V(onto_, diff), HHVM_GIT2_V(from_, diff));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_diff_find_similar,
	const Resource& diff,
	const Resource& options)
{
	int result;
	int64_t return_value;

	auto diff_ = dyn_cast<Git2Resource>(diff);
	auto options_ = dyn_cast<Git2Resource>(options);

	result = git_diff_find_similar(HHVM_GIT2_V(diff_, diff), HHVM_GIT2_V(options_, diff_find_options));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_diff_options_init,
	const Resource& options,
	int64_t version)
{
	int result;
	int64_t return_value;

	auto options_ = dyn_cast<Git2Resource>(options);

	result = git_diff_options_init(HHVM_GIT2_V(options_, diff_options), (unsigned int) version);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_diff_num_deltas,
	const Resource& diff)
{
	size_t result;
	int64_t return_value;

	auto diff_ = dyn_cast<Git2Resource>(diff);

	result = git_diff_num_deltas(HHVM_GIT2_V(diff_, diff));
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_diff_num_deltas_of_type,
	const Resource& diff,
	int64_t type)
{
	size_t result;
	int64_t return_value;

	auto diff_ = dyn_cast<Git2Resource>(diff);

	result = git_diff_num_deltas_of_type(HHVM_GIT2_V(diff_, diff), (git_delta_t) type);
	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_diff_get_delta,
	const Resource& diff,
	int64_t idx)
{
	const git_diff_delta *result;
	auto return_value = req::make<Git2Resource>();

	auto diff_ = dyn_cast<Git2Resource>(diff);

	result = git_diff_get_delta(HHVM_GIT2_V(diff_, diff), (size_t) idx);
	//HHVM_GIT2_V(return_value, diff_delta) = result; todo return as array
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_diff_is_sorted_icase,
	const Resource& diff)
{
	int result;
	int64_t return_value;

	auto diff_ = dyn_cast<Git2Resource>(diff);

	result = git_diff_is_sorted_icase(HHVM_GIT2_V(diff_, diff));

    if (result != GIT_OK && result != 1) {
        const git_error *error = giterr_last();
        SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_diff_foreach,
	const Resource& diff,
	const Variant& file_cb,
	const Variant& hunk_cb,
	const Variant& line_cb,
	const Variant& payload)
{
	int result;
	int64_t return_value;

	git_diff_file_cb file_cb_ = NULL;
	git_diff_hunk_cb hunk_cb_ = NULL;
	git_diff_line_cb line_cb_ = NULL;
	void *payload_ = NULL;

	auto diff_ = dyn_cast<Git2Resource>(diff);
	file_cb_ = NULL;
	hunk_cb_ = NULL;
	line_cb_ = NULL;

	result = git_diff_foreach(HHVM_GIT2_V(diff_, diff), /* todo */ file_cb_, /* todo */ hunk_cb_, /* todo */ line_cb_, payload_);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

String HHVM_FUNCTION(git_diff_status_char,
	int64_t status)
{
	char result;
	String return_value;

	result = git_diff_status_char((git_delta_t) status);
	return_value = String(&result);
	return return_value;
}

int64_t HHVM_FUNCTION(git_diff_print,
	const Resource& diff,
	int64_t format,
	const Variant& print_cb,
	const Variant& payload)
{
	int result;
	int64_t return_value;

	git_diff_line_cb print_cb_ = NULL;
	void *payload_ = NULL;

	auto diff_ = dyn_cast<Git2Resource>(diff);
	print_cb_ = NULL;

	result = git_diff_print(HHVM_GIT2_V(diff_, diff), (git_diff_format_t) format, print_cb_, payload_);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_diff_blobs,
	const Resource& old_blob,
	const String& old_as_path,
	const Resource& new_blob,
	const String& new_as_path,
	const Resource& options,
	const Variant& file_cb,
	const Variant& hunk_cb,
	const Variant& line_cb,
	const Variant& payload)
{
	int result;
	int64_t return_value;

	git_diff_file_cb file_cb_ = NULL;
	git_diff_hunk_cb hunk_cb_ = NULL;
	git_diff_line_cb line_cb_ = NULL;
	void *payload_ = NULL;

	auto old_blob_ = dyn_cast<Git2Resource>(old_blob);
	auto new_blob_ = dyn_cast<Git2Resource>(new_blob);
	auto options_ = dyn_cast<Git2Resource>(options);
	file_cb_ = NULL;
	hunk_cb_ = NULL;
	line_cb_ = NULL;

    //todo next
	result = git_diff_blobs(HHVM_GIT2_V(old_blob_, blob), old_as_path.c_str(), HHVM_GIT2_V(new_blob_, blob), new_as_path.c_str(), HHVM_GIT2_V(options_, diff_options), /* todo */ file_cb_, /* todo */ hunk_cb_, /* todo */ line_cb_, payload_);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

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
	const Variant& payload)
{
    int result;
    int64_t return_value;

	git_diff_file_cb file_cb_ = NULL;
	git_diff_hunk_cb hunk_cb_ = NULL;
	git_diff_line_cb line_cb_ = NULL;
	void *payload_ = NULL;
    
    auto old_blob_ = dyn_cast<Git2Resource>(old_blob);
	auto options_ = dyn_cast<Git2Resource>(options);
	file_cb_ = NULL;
	hunk_cb_ = NULL;
	line_cb_ = NULL;

    git_diff_blob_to_buffer(HHVM_GIT2_V(old_blob_, blob), old_as_path.c_str(), buffer.c_str(), (size_t) buffer_len, buffer_as_path.c_str(), HHVM_GIT2_V(options_, diff_options), /* todo */ file_cb_, /* todo */ hunk_cb_, /* todo */ line_cb_, payload_);
    return_value = (int64_t) result;
    return return_value;
}

