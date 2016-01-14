/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "revwalk.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_revwalk_new,
	const Resource& repo)
{
	auto return_value = req::make<Git2Resource>();

	git_revwalk *out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	git_revwalk_new(&out, HHVM_GIT2_V(repo_, repository));
	HHVM_GIT2_V(return_value, revwalk) = out;
	return Resource(return_value);
}

void HHVM_FUNCTION(git_revwalk_reset,
	const Resource& walker)
{

	auto walker_ = dyn_cast<Git2Resource>(walker);

	git_revwalk_reset(HHVM_GIT2_V(walker_, revwalk));
}

int64_t HHVM_FUNCTION(git_revwalk_push,
	const Resource& walk,
	const String& id)
{
	int result;
	int64_t return_value;

	git_oid id_;

	auto walk_ = dyn_cast<Git2Resource>(walk);
	if (git_oid_fromstr(&id_, id.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}

	result = git_revwalk_push(HHVM_GIT2_V(walk_, revwalk), &id_);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_revwalk_push_glob,
	const Resource& walk,
	const String& glob)
{
	int result;
	int64_t return_value;

	auto walk_ = dyn_cast<Git2Resource>(walk);

	result = git_revwalk_push_glob(HHVM_GIT2_V(walk_, revwalk), glob.c_str());
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_revwalk_push_head,
	const Resource& walk)
{
	int result;
	int64_t return_value;

	auto walk_ = dyn_cast<Git2Resource>(walk);

	result = git_revwalk_push_head(HHVM_GIT2_V(walk_, revwalk));
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_revwalk_hide,
	const Resource& walk,
	const String& commit_id)
{
	int result;
	int64_t return_value;

	git_oid commit_id_;

	auto walk_ = dyn_cast<Git2Resource>(walk);
	if (git_oid_fromstr(&commit_id_, commit_id.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}

	result = git_revwalk_hide(HHVM_GIT2_V(walk_, revwalk), &commit_id_);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_revwalk_hide_glob,
	const Resource& walk,
	const String& glob)
{
	int result;
	int64_t return_value;

	auto walk_ = dyn_cast<Git2Resource>(walk);

	result = git_revwalk_hide_glob(HHVM_GIT2_V(walk_, revwalk), glob.c_str());
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_revwalk_hide_head,
	const Resource& walk)
{
	int result;
	int64_t return_value;

	auto walk_ = dyn_cast<Git2Resource>(walk);

	result = git_revwalk_hide_head(HHVM_GIT2_V(walk_, revwalk));
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_revwalk_push_ref,
	const Resource& walk,
	const String& refname)
{
	int result;
	int64_t return_value;

	auto walk_ = dyn_cast<Git2Resource>(walk);

	result = git_revwalk_push_ref(HHVM_GIT2_V(walk_, revwalk), refname.c_str());
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_revwalk_hide_ref,
	const Resource& walk,
	const String& refname)
{
	int result;
	int64_t return_value;

	auto walk_ = dyn_cast<Git2Resource>(walk);

	result = git_revwalk_hide_ref(HHVM_GIT2_V(walk_, revwalk), refname.c_str());
	return_value = (int64_t) result;
	return return_value;
}

String HHVM_FUNCTION(git_revwalk_next,
	const Resource& walk)
{
	char return_value[GIT_OID_HEXSZ+1] = {0};

	git_oid out;

	auto walk_ = dyn_cast<Git2Resource>(walk);

	git_revwalk_next(&out, HHVM_GIT2_V(walk_, revwalk));
	git_oid_fmt(return_value, &out);
	return String(return_value);
}

void HHVM_FUNCTION(git_revwalk_sorting,
	const Resource& walk,
	int64_t sort_mode)
{

	auto walk_ = dyn_cast<Git2Resource>(walk);

	git_revwalk_sorting(HHVM_GIT2_V(walk_, revwalk), (unsigned int) sort_mode);
}

int64_t HHVM_FUNCTION(git_revwalk_push_range,
	const Resource& walk,
	const String& range)
{
	int result;
	int64_t return_value;

	auto walk_ = dyn_cast<Git2Resource>(walk);

	result = git_revwalk_push_range(HHVM_GIT2_V(walk_, revwalk), range.c_str());
	return_value = (int64_t) result;
	return return_value;
}

void HHVM_FUNCTION(git_revwalk_simplify_first_parent,
	const Resource& walk)
{

	auto walk_ = dyn_cast<Git2Resource>(walk);

	git_revwalk_simplify_first_parent(HHVM_GIT2_V(walk_, revwalk));
}

void HHVM_FUNCTION(git_revwalk_free,
	const Resource& walk)
{

	auto walk_ = dyn_cast<Git2Resource>(walk);

	git_revwalk_free(HHVM_GIT2_V(walk_, revwalk));
}

Resource HHVM_FUNCTION(git_revwalk_repository,
	const Resource& walk)
{
	git_repository *result;
	auto return_value = req::make<Git2Resource>();

	auto walk_ = dyn_cast<Git2Resource>(walk);

	result = git_revwalk_repository(HHVM_GIT2_V(walk_, revwalk));
	HHVM_GIT2_V(return_value, repository) = result;
	return Resource(return_value);
}

