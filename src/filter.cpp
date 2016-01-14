/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "filter.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_filter_list_load,
	const Resource& repo,
	const Resource& blob,
	const String& path,
	int64_t mode)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_filter_list *filters = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto blob_ = dyn_cast<Git2Resource>(blob);

	result = git_filter_list_load(&filters, HHVM_GIT2_V(repo_, repository), HHVM_GIT2_V(blob_, blob), path.c_str(), (git_filter_mode_t) mode);

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	HHVM_GIT2_V(return_value, filter_list) = filters;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_filter_list_apply_to_data,
	const Resource& filters,
	const Resource& in)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_buf out;

	auto filters_ = dyn_cast<Git2Resource>(filters);
	auto in_ = dyn_cast<Git2Resource>(in);

	result = git_filter_list_apply_to_data(&out, HHVM_GIT2_V(filters_, filter_list), HHVM_GIT2_V(in_, buf));

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	HHVM_GIT2_V(return_value, buf) = &out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_filter_list_apply_to_file,
	const Resource& filters,
	const Resource& repo,
	const String& path)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_buf out;

	auto filters_ = dyn_cast<Git2Resource>(filters);
	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_filter_list_apply_to_file(&out, HHVM_GIT2_V(filters_, filter_list), HHVM_GIT2_V(repo_, repository), path.c_str());

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	HHVM_GIT2_V(return_value, buf) = &out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_filter_list_apply_to_blob,
	const Resource& filters,
	const Resource& blob)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_buf out;

	auto filters_ = dyn_cast<Git2Resource>(filters);
	auto blob_ = dyn_cast<Git2Resource>(blob);

	result = git_filter_list_apply_to_blob(&out, HHVM_GIT2_V(filters_, filter_list), HHVM_GIT2_V(blob_, blob));

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	HHVM_GIT2_V(return_value, buf) = &out;
	return Resource(return_value);
}

void HHVM_FUNCTION(git_filter_list_free,
	const Resource& filters)
{

	auto filters_ = dyn_cast<Git2Resource>(filters);

	git_filter_list_free(HHVM_GIT2_V(filters_, filter_list));
}

