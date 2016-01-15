/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "sys_index.h"

using namespace HPHP;

int64_t HHVM_FUNCTION(git_index_name_entrycount,
	const Resource& index)
{
	int result;
	int64_t return_value;

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_name_entrycount(HHVM_GIT2_V(index_, index));

	if (result < 0) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_index_name_get_byindex,
	const Resource& index,
	int64_t n)
{
	const git_index_name_entry *result;
	auto return_value = req::make<Git2Resource>();

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_name_get_byindex(HHVM_GIT2_V(index_, index), (size_t) n);
	//HHVM_GIT2_V(return_value, index_name_entry) = result; todo return as array
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_index_name_add,
	const Resource& index,
	const String& ancestor,
	const String& ours,
	const String& theirs)
{
	int result;
	int64_t return_value;

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_name_add(HHVM_GIT2_V(index_, index), ancestor.c_str(), ours.c_str(), theirs.c_str());

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

void HHVM_FUNCTION(git_index_name_clear,
	const Resource& index)
{

	auto index_ = dyn_cast<Git2Resource>(index);

	git_index_name_clear(HHVM_GIT2_V(index_, index));
}

int64_t HHVM_FUNCTION(git_index_reuc_entrycount,
	const Resource& index)
{
	int result;
	int64_t return_value;

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_reuc_entrycount(HHVM_GIT2_V(index_, index));

    if (result < 0) {
        const git_error *error = giterr_last();
        SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_index_reuc_find,
	int64_t at_pos,
	const Resource& index,
	const String& path)
{
	int result;
	int64_t return_value;

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_reuc_find((size_t*) at_pos, HHVM_GIT2_V(index_, index), path.c_str());

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_index_reuc_get_bypath,
	const Resource& index,
	const String& path)
{
	const git_index_reuc_entry *result;
	auto return_value = req::make<Git2Resource>();

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_reuc_get_bypath(HHVM_GIT2_V(index_, index), path.c_str());
	//HHVM_GIT2_V(return_value, index_reuc_entry) = result; todo return as array
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_index_reuc_get_byindex,
	const Resource& index,
	int64_t n)
{
	const git_index_reuc_entry *result;
	auto return_value = req::make<Git2Resource>();

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_reuc_get_byindex(HHVM_GIT2_V(index_, index), (size_t) n);
	//HHVM_GIT2_V(return_value, index_reuc_entry) = result; todo return as array
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_index_reuc_add,
	const Resource& index,
	const String& path,
	int64_t ancestor_mode,
	const String& ancestor_id,
	int64_t our_mode,
	const String& our_id,
	int64_t their_mode,
	const String& their_id)
{
	int result;
	int64_t return_value;

	git_oid ancestor_id_;
	git_oid our_id_;
	git_oid their_id_;

	auto index_ = dyn_cast<Git2Resource>(index);
	if (git_oid_fromstr(&ancestor_id_, ancestor_id.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}
	if (git_oid_fromstr(&our_id_, our_id.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}
	if (git_oid_fromstr(&their_id_, their_id.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}

	result = git_index_reuc_add(HHVM_GIT2_V(index_, index), path.c_str(), (int) ancestor_mode, &ancestor_id_, (int) our_mode, &our_id_, (int) their_mode, &their_id_);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_index_reuc_remove,
	const Resource& index,
	int64_t n)
{
	int result;
	int64_t return_value;

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_reuc_remove(HHVM_GIT2_V(index_, index), (size_t) n);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

void HHVM_FUNCTION(git_index_reuc_clear,
	const Resource& index)
{

	auto index_ = dyn_cast<Git2Resource>(index);

	git_index_reuc_clear(HHVM_GIT2_V(index_, index));
}

