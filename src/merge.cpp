/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/system/systemlib.h"

#include "merge.h"

using namespace HPHP;

String HHVM_FUNCTION(git_merge_base,
	const Resource& repo,
	const String& one,
	const String& two)
{
	char *return_value;

	git_oid *out = NULL;
	git_oid *one_ = NULL;
	git_oid *two_ = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	if (git_oid_fromstrn(one_, one.c_str(), one.length())) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}
	if (git_oid_fromstrn(two_, two.c_str(), two.length())) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}

	git_merge_base(out, HHVM_GIT2_V(repo_, repository), one_, two_);
	git_oid_fmt(return_value, out);
	return String(return_value);
}

String HHVM_FUNCTION(git_merge_base_many,
	const Resource& repo,
	int64_t length,
	const String& input_array)
{
	char *return_value;

	git_oid *out = NULL;
	git_oid *input_array_ = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	if (git_oid_fromstrn(input_array_, input_array.c_str(), input_array.length())) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}

	git_merge_base_many(out, HHVM_GIT2_V(repo_, repository), (size_t) length, input_array_);
	git_oid_fmt(return_value, out);
	return String(return_value);
}

Resource HHVM_FUNCTION(git_merge_head_from_ref,
	const Resource& repo,
	const Resource& ref)
{
	auto return_value = req::make<Git2Resource>();

	git_merge_head **out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto ref_ = dyn_cast<Git2Resource>(ref);

	git_merge_head_from_ref(out, HHVM_GIT2_V(repo_, repository), HHVM_GIT2_V(ref_, reference));
	HHVM_GIT2_V(return_value, merge_head) = *out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_merge_head_from_fetchhead,
	const Resource& repo,
	const String& branch_name,
	const String& remote_url,
	const String& oid)
{
	auto return_value = req::make<Git2Resource>();

	git_merge_head **out = NULL;
	git_oid *oid_ = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	if (git_oid_fromstrn(oid_, oid.c_str(), oid.length())) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}

	git_merge_head_from_fetchhead(out, HHVM_GIT2_V(repo_, repository), branch_name.c_str(), remote_url.c_str(), oid_);
	HHVM_GIT2_V(return_value, merge_head) = *out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_merge_head_from_oid,
	const Resource& repo,
	const String& oid)
{
	auto return_value = req::make<Git2Resource>();

	git_merge_head **out = NULL;
	git_oid *oid_ = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	if (git_oid_fromstrn(oid_, oid.c_str(), oid.length())) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}

	git_merge_head_from_oid(out, HHVM_GIT2_V(repo_, repository), oid_);
	HHVM_GIT2_V(return_value, merge_head) = *out;
	return Resource(return_value);
}

void HHVM_FUNCTION(git_merge_head_free,
	const Resource& head)
{

	auto head_ = dyn_cast<Git2Resource>(head);

	git_merge_head_free(HHVM_GIT2_V(head_, merge_head));
}

Resource HHVM_FUNCTION(git_merge_trees,
	const Resource& repo,
	const Resource& ancestor_tree,
	const Resource& our_tree,
	const Resource& their_tree,
	const Resource& opts)
{
	auto return_value = req::make<Git2Resource>();

	git_index **out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto ancestor_tree_ = dyn_cast<Git2Resource>(ancestor_tree);
	auto our_tree_ = dyn_cast<Git2Resource>(our_tree);
	auto their_tree_ = dyn_cast<Git2Resource>(their_tree);
	auto opts_ = dyn_cast<Git2Resource>(opts);

	git_merge_trees(out, HHVM_GIT2_V(repo_, repository), HHVM_GIT2_V(ancestor_tree_, tree), HHVM_GIT2_V(our_tree_, tree), HHVM_GIT2_V(their_tree_, tree), HHVM_GIT2_V(opts_, merge_tree_opts));
	HHVM_GIT2_V(return_value, index) = *out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_merge,
	const Resource& repo,
	const Resource& their_heads,
	const Resource& opts)
{
	Git2Resource *return_value = new Git2Resource();
	const git_merge_head *heads[1];
    
	git_merge_result **out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto their_heads_ = dyn_cast<Git2Resource>(their_heads);
	auto opts_ = dyn_cast<Git2Resource>(opts);
    
    heads[0] = HHVM_GIT2_V(their_heads_, merge_head);

	git_merge(out, HHVM_GIT2_V(repo_, repository), heads, 1, HHVM_GIT2_V(opts_, merge_opts));
	HHVM_GIT2_V(return_value, merge_result) = *out;
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_merge_result_is_uptodate,
	const Resource& merge_result)
{
	int result;
	int64_t return_value;

	auto merge_result_ = dyn_cast<Git2Resource>(merge_result);

	result = git_merge_result_is_uptodate(HHVM_GIT2_V(merge_result_, merge_result));
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_merge_result_is_fastforward,
	const Resource& merge_result)
{
	int result;
	int64_t return_value;

	auto merge_result_ = dyn_cast<Git2Resource>(merge_result);

	result = git_merge_result_is_fastforward(HHVM_GIT2_V(merge_result_, merge_result));
	return_value = (int64_t) result;
	return return_value;
}

String HHVM_FUNCTION(git_merge_result_fastforward_oid,
	const Resource& merge_result)
{
	char *return_value;

	git_oid *out = NULL;

	auto merge_result_ = dyn_cast<Git2Resource>(merge_result);

	git_merge_result_fastforward_oid(out, HHVM_GIT2_V(merge_result_, merge_result));
	git_oid_fmt(return_value, out);
	return String(return_value);
}

void HHVM_FUNCTION(git_merge_result_free,
	const Resource& merge_result)
{

	auto merge_result_ = dyn_cast<Git2Resource>(merge_result);

	git_merge_result_free(HHVM_GIT2_V(merge_result_, merge_result));
}

