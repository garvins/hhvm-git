/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "pathspec.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_pathspec_new,
	const Resource& pathspec)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_pathspec *out = NULL;

	auto pathspec_ = dyn_cast<Git2Resource>(pathspec);

	result = git_pathspec_new(&out, HHVM_GIT2_V(pathspec_, strarray));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, pathspec) = out;
	return Resource(return_value);
}

void HHVM_FUNCTION(git_pathspec_free,
	const Resource& ps)
{

	auto ps_ = dyn_cast<Git2Resource>(ps);

	git_pathspec_free(HHVM_GIT2_V(ps_, pathspec));
}

int64_t HHVM_FUNCTION(git_pathspec_matches_path,
	const Resource& ps,
	int64_t flags,
	const String& path)
{
	int result;
	int64_t return_value;

	auto ps_ = dyn_cast<Git2Resource>(ps);

	result = git_pathspec_matches_path(HHVM_GIT2_V(ps_, pathspec), (uint32_t) flags, path.c_str());

	if (result != GIT_OK && result != 1) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_pathspec_match_workdir,
	const Resource& repo,
	int64_t flags,
	const Resource& ps)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_pathspec_match_list *out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto ps_ = dyn_cast<Git2Resource>(ps);

	result = git_pathspec_match_workdir(&out, HHVM_GIT2_V(repo_, repository), (uint32_t) flags, HHVM_GIT2_V(ps_, pathspec));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, pathspec_match_list) = out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_pathspec_match_index,
	const Resource& index,
	int64_t flags,
	const Resource& ps)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_pathspec_match_list *out = NULL;

	auto index_ = dyn_cast<Git2Resource>(index);
	auto ps_ = dyn_cast<Git2Resource>(ps);

	result = git_pathspec_match_index(&out, HHVM_GIT2_V(index_, index), (uint32_t) flags, HHVM_GIT2_V(ps_, pathspec));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, pathspec_match_list) = out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_pathspec_match_tree,
	const Resource& tree,
	int64_t flags,
	const Resource& ps)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_pathspec_match_list *out = NULL;

	auto tree_ = dyn_cast<Git2Resource>(tree);
	auto ps_ = dyn_cast<Git2Resource>(ps);

	result = git_pathspec_match_tree(&out, HHVM_GIT2_V(tree_, tree), (uint32_t) flags, HHVM_GIT2_V(ps_, pathspec));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, pathspec_match_list) = out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_pathspec_match_diff,
	const Resource& diff,
	int64_t flags,
	const Resource& ps)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_pathspec_match_list *out = NULL;

	auto diff_ = dyn_cast<Git2Resource>(diff);
	auto ps_ = dyn_cast<Git2Resource>(ps);

	result = git_pathspec_match_diff(&out, HHVM_GIT2_V(diff_, diff), (uint32_t) flags, HHVM_GIT2_V(ps_, pathspec));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, pathspec_match_list) = out;
	return Resource(return_value);
}

void HHVM_FUNCTION(git_pathspec_match_list_free,
	const Resource& m)
{

	auto m_ = dyn_cast<Git2Resource>(m);

	git_pathspec_match_list_free(HHVM_GIT2_V(m_, pathspec_match_list));
}

int64_t HHVM_FUNCTION(git_pathspec_match_list_entrycount,
	const Resource& m)
{
	size_t result;
	int64_t return_value;

	auto m_ = dyn_cast<Git2Resource>(m);

	result = git_pathspec_match_list_entrycount(HHVM_GIT2_V(m_, pathspec_match_list));
	return_value = (int64_t) result;
	return return_value;
}

String HHVM_FUNCTION(git_pathspec_match_list_entry,
	const Resource& m,
	int64_t pos)
{
	const char *result;
	String return_value;

	auto m_ = dyn_cast<Git2Resource>(m);

	result = git_pathspec_match_list_entry(HHVM_GIT2_V(m_, pathspec_match_list), (size_t) pos);
	return_value = String(result);
	return return_value;
}

Resource HHVM_FUNCTION(git_pathspec_match_list_diff_entry,
	const Resource& m,
	int64_t pos)
{
	const git_diff_delta *result;
	auto return_value = req::make<Git2Resource>();

	auto m_ = dyn_cast<Git2Resource>(m);

	result = git_pathspec_match_list_diff_entry(HHVM_GIT2_V(m_, pathspec_match_list), (size_t) pos);
	//HHVM_GIT2_V(return_value, diff_delta) = result; todo return as array
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_pathspec_match_list_failed_entrycount,
	const Resource& m)
{
	size_t result;
	int64_t return_value;

	auto m_ = dyn_cast<Git2Resource>(m);

	result = git_pathspec_match_list_failed_entrycount(HHVM_GIT2_V(m_, pathspec_match_list));
	return_value = (int64_t) result;
	return return_value;
}

String HHVM_FUNCTION(git_pathspec_match_list_failed_entry,
	const Resource& m,
	int64_t pos)
{
	const char *result;
	String return_value;

	auto m_ = dyn_cast<Git2Resource>(m);

	result = git_pathspec_match_list_failed_entry(HHVM_GIT2_V(m_, pathspec_match_list), (size_t) pos);
	return_value = String(result);
	return return_value;
}

