/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "branch.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_branch_create,
	const Resource& repo,
	const String& branch_name,
	const Resource& target,
	int64_t force)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_reference *out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto target_ = dyn_cast<Git2Resource>(target);

	result = git_branch_create(&out, HHVM_GIT2_V(repo_, repository), branch_name.c_str(), HHVM_GIT2_V(target_, commit), (int) force);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, reference) = out;
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_branch_delete,
	const Resource& branch)
{
	int result;
	int64_t return_value;

	auto branch_ = dyn_cast<Git2Resource>(branch);

	result = git_branch_delete(HHVM_GIT2_V(branch_, reference));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_branch_iterator_new,
	const Resource& repo,
	int64_t list_flags)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_branch_iterator *out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_branch_iterator_new(&out, HHVM_GIT2_V(repo_, repository), (git_branch_t) list_flags);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, branch_iterator) = out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_branch_next,
	int64_t out_type,
	const Resource& iter)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_reference *out = NULL;

	auto iter_ = dyn_cast<Git2Resource>(iter);

	result = git_branch_next(&out, (git_branch_t*) out_type, HHVM_GIT2_V(iter_, branch_iterator));

	if (result == GIT_ITEROVER) {
		/* todo return nullptr */
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	} else if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, reference) = out;
	return Resource(return_value);
}

void HHVM_FUNCTION(git_branch_iterator_free,
	const Resource& iter)
{

	auto iter_ = dyn_cast<Git2Resource>(iter);

	git_branch_iterator_free(HHVM_GIT2_V(iter_, branch_iterator));
}

Resource HHVM_FUNCTION(git_branch_move,
	const Resource& branch,
	const String& new_branch_name,
	int64_t force)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_reference *out = NULL;

	auto branch_ = dyn_cast<Git2Resource>(branch);

	result = git_branch_move(&out, HHVM_GIT2_V(branch_, reference), new_branch_name.c_str(), (int) force);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, reference) = out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_branch_lookup,
	const Resource& repo,
	const String& branch_name,
	int64_t branch_type)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_reference *out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_branch_lookup(&out, HHVM_GIT2_V(repo_, repository), branch_name.c_str(), (git_branch_t) branch_type);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, reference) = out;
	return Resource(return_value);
}

String HHVM_FUNCTION(git_branch_name,
	const Resource& ref)
{
	int result;
	String return_value;

	const char *out = NULL;

	auto ref_ = dyn_cast<Git2Resource>(ref);

	result = git_branch_name(&out, HHVM_GIT2_V(ref_, reference));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}


	if (out != NULL) {
		return_value = String(out);
	} else {
		return_value = "";
	}

	return return_value;
}

Resource HHVM_FUNCTION(git_branch_upstream,
	const Resource& branch)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_reference *out = NULL;

	auto branch_ = dyn_cast<Git2Resource>(branch);

	result = git_branch_upstream(&out, HHVM_GIT2_V(branch_, reference));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, reference) = out;
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_branch_set_upstream,
	const Resource& branch,
	const String& upstream_name)
{
	int result;
	int64_t return_value;

	auto branch_ = dyn_cast<Git2Resource>(branch);

	result = git_branch_set_upstream(HHVM_GIT2_V(branch_, reference), upstream_name.c_str());

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

String HHVM_FUNCTION(git_branch_upstream_name,
	int64_t buffer_size,
	const Resource& repo,
	const String& canonical_branch_name)
{
	int result;
	String return_value;

	char tracking_branch_name_out;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_branch_upstream_name(&tracking_branch_name_out, (size_t) buffer_size, HHVM_GIT2_V(repo_, repository), canonical_branch_name.c_str());

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}


	if (&tracking_branch_name_out != NULL) {
		return_value = String(&tracking_branch_name_out);
	} else {
		return_value = "";
	}

	return return_value;
}

int64_t HHVM_FUNCTION(git_branch_is_head,
	const Resource& branch)
{
	int result;
	int64_t return_value;

	auto branch_ = dyn_cast<Git2Resource>(branch);

	result = git_branch_is_head(HHVM_GIT2_V(branch_, reference));

	if (result != GIT_OK && result != 1) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

String HHVM_FUNCTION(git_branch_remote_name,
	int64_t buffer_size,
	const Resource& repo,
	const String& canonical_branch_name)
{
	int result;
	String return_value;

	char remote_name_out;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_branch_remote_name(&remote_name_out, (size_t) buffer_size, HHVM_GIT2_V(repo_, repository), canonical_branch_name.c_str());

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}


	if (&remote_name_out != NULL) {
		return_value = String(&remote_name_out);
	} else {
		return_value = "";
	}

	return return_value;
}

