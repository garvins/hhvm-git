/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/runtime/ext/extension.h"
#include "hphp/system/systemlib.h"

#include "../ext_git2.h"
#include "commit.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_commit_lookup,
	const Resource& repo,
	const String& id)
{
	Git2Resource *return_value = new Git2Resource();

	git_commit **commit = NULL;
	git_oid *id_ = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	if (git_oid_fromstrn(id_, id.c_str(), id.length())) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}

	git_commit_lookup(commit, HHVM_GIT2_V(repo_, repository), id_);
	HHVM_GIT2_V(return_value, commit) = *commit;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_commit_lookup_prefix,
	const Resource& repo,
	const String& id,
	int64_t len)
{
	Git2Resource *return_value = new Git2Resource();

	git_commit **commit = NULL;
	git_oid *id_ = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	if (git_oid_fromstrn(id_, id.c_str(), id.length())) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}

	git_commit_lookup_prefix(commit, HHVM_GIT2_V(repo_, repository), id_, (size_t) len);
	HHVM_GIT2_V(return_value, commit) = *commit;
	return Resource(return_value);
}

void HHVM_FUNCTION(git_commit_free,
	const Resource& commit)
{

	auto commit_ = dyn_cast<Git2Resource>(commit);

	git_commit_free(HHVM_GIT2_V(commit_, commit));
}

String HHVM_FUNCTION(git_commit_id,
	const Resource& commit)
{
	const git_oid *result;
	char *return_value;

	auto commit_ = dyn_cast<Git2Resource>(commit);

	result = git_commit_id(HHVM_GIT2_V(commit_, commit));
	git_oid_fmt(return_value, result);
	return String(return_value);
}

Resource HHVM_FUNCTION(git_commit_owner,
	const Resource& commit)
{
	git_repository *result;
	Git2Resource *return_value = new Git2Resource();

	auto commit_ = dyn_cast<Git2Resource>(commit);

	result = git_commit_owner(HHVM_GIT2_V(commit_, commit));
	HHVM_GIT2_V(return_value, repository) = result;
	return Resource(return_value);
}

String HHVM_FUNCTION(git_commit_message_encoding,
	const Resource& commit)
{
	const char *result;
	String return_value;

	auto commit_ = dyn_cast<Git2Resource>(commit);

	result = git_commit_message_encoding(HHVM_GIT2_V(commit_, commit));
	return_value = String(result);
	return return_value;
}

String HHVM_FUNCTION(git_commit_message,
	const Resource& commit)
{
	const char *result;
	String return_value;

	auto commit_ = dyn_cast<Git2Resource>(commit);

	result = git_commit_message(HHVM_GIT2_V(commit_, commit));
	return_value = String(result);
	return return_value;
}

String HHVM_FUNCTION(git_commit_message_raw,
	const Resource& commit)
{
	const char *result;
	String return_value;

	auto commit_ = dyn_cast<Git2Resource>(commit);

	result = git_commit_message_raw(HHVM_GIT2_V(commit_, commit));
	return_value = String(result);
	return return_value;
}

int64_t HHVM_FUNCTION(git_commit_time,
	const Resource& commit)
{
	git_time_t result;
	int64_t return_value;

	auto commit_ = dyn_cast<Git2Resource>(commit);

	result = git_commit_time(HHVM_GIT2_V(commit_, commit));
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_commit_time_offset,
	const Resource& commit)
{
	int result;
	int64_t return_value;

	auto commit_ = dyn_cast<Git2Resource>(commit);

	result = git_commit_time_offset(HHVM_GIT2_V(commit_, commit));
	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_commit_committer,
	const Resource& commit)
{
	const git_signature *result;
	Git2Resource *return_value = new Git2Resource();

	auto commit_ = dyn_cast<Git2Resource>(commit);

	result = git_commit_committer(HHVM_GIT2_V(commit_, commit));
	//HHVM_GIT2_V(return_value, signature) = result; todo return as array
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_commit_author,
	const Resource& commit)
{
	const git_signature *result;
	Git2Resource *return_value = new Git2Resource();

	auto commit_ = dyn_cast<Git2Resource>(commit);

	result = git_commit_author(HHVM_GIT2_V(commit_, commit));
	//HHVM_GIT2_V(return_value, signature) = result; todo return as array
	return Resource(return_value);
}

String HHVM_FUNCTION(git_commit_raw_header,
	const Resource& commit)
{
	const char *result;
	String return_value;

	auto commit_ = dyn_cast<Git2Resource>(commit);

	result = git_commit_raw_header(HHVM_GIT2_V(commit_, commit));
	return_value = String(result);
	return return_value;
}

Resource HHVM_FUNCTION(git_commit_tree,
	const Resource& commit)
{
	Git2Resource *return_value = new Git2Resource();

	git_tree **tree_out = NULL;

	auto commit_ = dyn_cast<Git2Resource>(commit);

	git_commit_tree(tree_out, HHVM_GIT2_V(commit_, commit));
	HHVM_GIT2_V(return_value, tree) = *tree_out;
	return Resource(return_value);
}

String HHVM_FUNCTION(git_commit_tree_id,
	const Resource& commit)
{
	const git_oid *result;
	char *return_value;

	auto commit_ = dyn_cast<Git2Resource>(commit);

	result = git_commit_tree_id(HHVM_GIT2_V(commit_, commit));
	git_oid_fmt(return_value, result);
	return String(return_value);
}

int64_t HHVM_FUNCTION(git_commit_parentcount,
	const Resource& commit)
{
	int result;
	int64_t return_value;

	auto commit_ = dyn_cast<Git2Resource>(commit);

	result = git_commit_parentcount(HHVM_GIT2_V(commit_, commit));
	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_commit_parent,
	const Resource& commit,
	int64_t n)
{
	Git2Resource *return_value = new Git2Resource();

	git_commit **out = NULL;

	auto commit_ = dyn_cast<Git2Resource>(commit);

	git_commit_parent(out, HHVM_GIT2_V(commit_, commit), (unsigned int) n);
	HHVM_GIT2_V(return_value, commit) = *out;
	return Resource(return_value);
}

String HHVM_FUNCTION(git_commit_parent_id,
	const Resource& commit,
	int64_t n)
{
	const git_oid *result;
	char *return_value;

	auto commit_ = dyn_cast<Git2Resource>(commit);

	result = git_commit_parent_id(HHVM_GIT2_V(commit_, commit), (unsigned int) n);
	git_oid_fmt(return_value, result);
	return String(return_value);
}

Resource HHVM_FUNCTION(git_commit_nth_gen_ancestor,
	const Resource& commit,
	int64_t n)
{
    Git2Resource *return_value = new Git2Resource();

	git_commit **ancestor;

	auto commit_ = dyn_cast<Git2Resource>(commit);

    git_commit_nth_gen_ancestor(ancestor, HHVM_GIT2_V(commit_, commit), (unsigned int) n);
    HHVM_GIT2_V(return_value, commit) = *ancestor;
    return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_commit_create,
	const String& id,
	const Resource& repo,
	const String& update_ref,
	const Resource& author,
	const Resource& committer,
	const String& message_encoding,
	const String& message,
	const Resource& tree,
	int64_t parent_count,
	const Array& parents)
{
	int result;
	int64_t return_value;

	git_oid *id_ = NULL;

	if (git_oid_fromstrn(id_, id.c_str(), id.length())) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}
	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto author_ = dyn_cast<Git2Resource>(author);
	auto committer_ = dyn_cast<Git2Resource>(committer);
	auto tree_ = dyn_cast<Git2Resource>(tree);
	// auto parents_ = dyn_cast<Git2Resource>(parents); todo get array values

	result = git_commit_create(id_, HHVM_GIT2_V(repo_, repository), update_ref.c_str(), HHVM_GIT2_V(author_, signature), HHVM_GIT2_V(committer_, signature), message_encoding.c_str(), message.c_str(), HHVM_GIT2_V(tree_, tree), (int) parent_count, NULL /*HHVM_GIT2_V(parents_, commit) todo */);
	return_value = (int64_t) result;
	return return_value;
}

// todo
/* int64_t HHVM_FUNCTION(git_commit_create_v,
	const String& id,
	const Resource& repo,
	const String& update_ref,
	const Resource& author,
	const Resource& committer,
	const String& message_encoding,
	const String& message,
	const Resource& tree,
	int64_t parent_count,
	const Variant& )
{
	int result;
	int64_t return_value;

	git_oid *id_ = NULL;
	... _ = NULL;

	if (git_oid_fromstrn(id_, id.c_str(), id.length())) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}
	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto author_ = dyn_cast<Git2Resource>(author);
	auto committer_ = dyn_cast<Git2Resource>(committer);
	auto tree_ = dyn_cast<Git2Resource>(tree);

	result = git_commit_create_v(id_, HHVM_GIT2_V(repo_, repository), update_ref.c_str(), HHVM_GIT2_V(author_, signature), HHVM_GIT2_V(committer_, signature), message_encoding.c_str(), message.c_str(), HHVM_GIT2_V(tree_, tree), (int) parent_count, _);
	return_value = (int64_t) result;
	return return_value;
} */