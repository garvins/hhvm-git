/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/runtime/base/array-init.h"
#include "commit.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_commit_lookup,
	const Resource& repo,
	const String& id)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_commit *commit = NULL;
	git_oid id_;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	if (git_oid_fromstr(&id_, id.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	result = git_commit_lookup(&commit, HHVM_GIT2_V(repo_, repository), &id_);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, commit) = commit;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_commit_lookup_prefix,
	const Resource& repo,
	const String& id,
	int64_t len)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_commit *commit = NULL;
	git_oid id_;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	if (git_oid_fromstr(&id_, id.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	result = git_commit_lookup_prefix(&commit, HHVM_GIT2_V(repo_, repository), &id_, (size_t) len);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, commit) = commit;
	return Resource(return_value);
}

void HHVM_FUNCTION(git_commit_free,
	const Resource& commit)
{
	auto commit_ = dyn_cast<Git2Resource>(commit);

	git_commit_free(HHVM_GIT2_V(commit_, commit));
    
    // todo free resource, too
}

String HHVM_FUNCTION(git_commit_id,
	const Resource& commit)
{
	const git_oid *result;
	char return_value[GIT_OID_HEXSZ+1] = {0};

	auto commit_ = dyn_cast<Git2Resource>(commit);

	result = git_commit_id(HHVM_GIT2_V(commit_, commit));
	git_oid_fmt(return_value, result);
	return String(return_value);
}

Resource HHVM_FUNCTION(git_commit_owner,
	const Resource& commit)
{
	git_repository *result;
	auto return_value = req::make<Git2Resource>();

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

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_commit_committer,
	const Resource& commit)
{
	const git_signature *result;
	auto return_value = req::make<Git2Resource>();

	auto commit_ = dyn_cast<Git2Resource>(commit);

	result = git_commit_committer(HHVM_GIT2_V(commit_, commit));
	//HHVM_GIT2_V(return_value, signature) = result; todo return as array
	return Resource(return_value);
}

Array HHVM_FUNCTION(git_commit_author,
	const Resource& commit)
{
    char *name = NULL, *email = NULL;
    const git_signature *result;
    Array return_value;
    
	auto commit_ = dyn_cast<Git2Resource>(commit);

	result = git_commit_author(HHVM_GIT2_V(commit_, commit));
    
    if (result->name != NULL) {
        name = result->name;
    }
    
    if (result->email != NULL) {
        email = result->email;
    }
    
    return_value = make_map_array("name" , name, "email", email, "time", 0 /* todo return time */);
    
	return return_value;
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
	int result;
	auto return_value = req::make<Git2Resource>();

	git_tree *tree_out = NULL;

	auto commit_ = dyn_cast<Git2Resource>(commit);

	result = git_commit_tree(&tree_out, HHVM_GIT2_V(commit_, commit));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, tree) = tree_out;
	return Resource(return_value);
}

String HHVM_FUNCTION(git_commit_tree_id,
	const Resource& commit)
{
	const git_oid *result;
	char return_value[GIT_OID_HEXSZ+1] = {0};

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

	if (result < 0) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_commit_parent,
	const Resource& commit,
	int64_t n)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_commit *out = NULL;

	auto commit_ = dyn_cast<Git2Resource>(commit);

	result = git_commit_parent(&out, HHVM_GIT2_V(commit_, commit), (unsigned int) n);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, commit) = out;
	return Resource(return_value);
}

String HHVM_FUNCTION(git_commit_parent_id,
	const Resource& commit,
	int64_t n)
{
	const git_oid *result;
	char return_value[GIT_OID_HEXSZ+1] = {0};

	auto commit_ = dyn_cast<Git2Resource>(commit);

	result = git_commit_parent_id(HHVM_GIT2_V(commit_, commit), (unsigned int) n);
	git_oid_fmt(return_value, result);
	return String(return_value);
}

Resource HHVM_FUNCTION(git_commit_nth_gen_ancestor,
	const Resource& commit,
	int64_t n)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_commit *ancestor = NULL;

	auto commit_ = dyn_cast<Git2Resource>(commit);

	result = git_commit_nth_gen_ancestor(&ancestor, HHVM_GIT2_V(commit_, commit), (unsigned int) n);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, commit) = ancestor;
	return Resource(return_value);
}

String HHVM_FUNCTION(git_commit_create,
	const Resource& repo,
	const String& update_ref,
	const Array& author,
	const Array& committer,
	const String& message_encoding,
	const String& message,
	const Resource& tree,
	const Array& parents)
{
    int result, parent_count;
    char return_value[GIT_OID_HEXSZ+1] = {0};
    const git_commit **__parents = NULL;
	git_signature *__author, *__committer;
	git_oid id;
	
	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto tree_ = dyn_cast<Git2Resource>(tree);
	
	parent_count = (int) parents.size();
	
	__author = (git_signature*) malloc(sizeof(git_signature*));
	__committer = (git_signature*) malloc(sizeof(git_signature*));
	
	__author->name = author[String("name")].toString().mutableData();
	__author->email = author[String("email")].toString().mutableData();
	__author->when.time = (git_time_t) 0; //todo
	__author->when.offset = (int) 0; //todo
	
	__committer->name = committer[String("name")].toString().mutableData();
	__committer->email = committer[String("email")].toString().mutableData();
	__committer->when.time = (git_time_t) 0; //todo
	__committer->when.offset = (int) 0; //todo
	
	__parents = (const git_commit**) malloc(parent_count * sizeof(git_commit*));
    for(int i = 0; i < parent_count; i++) {
        auto p = dyn_cast<Git2Resource>(parents[i].toResource());
        __parents[i] = HHVM_GIT2_V(p, commit);
    }
	
	result = git_commit_create(&id, HHVM_GIT2_V(repo_, repository), update_ref.c_str(), __author, __committer, message_encoding.c_str(), message.c_str(), HHVM_GIT2_V(tree_, tree), (int) parent_count, __parents);
    
	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	git_oid_fmt(return_value, &id);
	return String(return_value);
}

String HHVM_FUNCTION(git_commit_create_v,
	const Resource& repo,
	const String& update_ref,
	const Resource& author,
	const Resource& committer,
	const String& message_encoding,
	const String& message,
	const Resource& tree,
	int64_t parent_count)
{
	int result;
	char return_value[GIT_OID_HEXSZ+1] = {0};

	git_oid id;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto author_ = dyn_cast<Git2Resource>(author);
	auto committer_ = dyn_cast<Git2Resource>(committer);
	auto tree_ = dyn_cast<Git2Resource>(tree);

	result = git_commit_create_v(&id, HHVM_GIT2_V(repo_, repository), update_ref.c_str(), HHVM_GIT2_V(author_, signature), HHVM_GIT2_V(committer_, signature), message_encoding.c_str(), message.c_str(), HHVM_GIT2_V(tree_, tree), (int) parent_count);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	git_oid_fmt(return_value, &id);
	return String(return_value);
}

