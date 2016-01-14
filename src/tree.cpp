/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "tree.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_tree_lookup,
	const Resource& repo,
	const String& id)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_tree *out = NULL;
	git_oid id_;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	if (git_oid_fromstr(&id_, id.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}

	result = git_tree_lookup(&out, HHVM_GIT2_V(repo_, repository), &id_);

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	HHVM_GIT2_V(return_value, tree) = out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_tree_lookup_prefix,
	const Resource& repo,
	const String& id,
	int64_t len)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_tree *out = NULL;
	git_oid id_;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	if (git_oid_fromstr(&id_, id.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}

	result = git_tree_lookup_prefix(&out, HHVM_GIT2_V(repo_, repository), &id_, (size_t) len);

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	HHVM_GIT2_V(return_value, tree) = out;
	return Resource(return_value);
}

void HHVM_FUNCTION(git_tree_free,
	const Resource& tree)
{

	auto tree_ = dyn_cast<Git2Resource>(tree);

	git_tree_free(HHVM_GIT2_V(tree_, tree));
    
    // todo free resource, too
}

String HHVM_FUNCTION(git_tree_id,
	const Resource& tree)
{
	const git_oid *result;
	char return_value[GIT_OID_HEXSZ+1] = {0};

	auto tree_ = dyn_cast<Git2Resource>(tree);

	result = git_tree_id(HHVM_GIT2_V(tree_, tree));
	git_oid_fmt(return_value, result);
	return String(return_value);
}

Resource HHVM_FUNCTION(git_tree_owner,
	const Resource& tree)
{
	git_repository *result;
	auto return_value = req::make<Git2Resource>();

	auto tree_ = dyn_cast<Git2Resource>(tree);

	result = git_tree_owner(HHVM_GIT2_V(tree_, tree));
	HHVM_GIT2_V(return_value, repository) = result;
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_tree_entrycount,
	const Resource& tree)
{
	size_t result;
	int64_t return_value;

	auto tree_ = dyn_cast<Git2Resource>(tree);

	result = git_tree_entrycount(HHVM_GIT2_V(tree_, tree));
	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_tree_entry_byname,
	const Resource& tree,
	const String& filename)
{
	const git_tree_entry *result;
	auto return_value = req::make<Git2Resource>();

	auto tree_ = dyn_cast<Git2Resource>(tree);

	result = git_tree_entry_byname(HHVM_GIT2_V(tree_, tree), filename.c_str());
	//HHVM_GIT2_V(return_value, tree_entry) = result; todo return as array
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_tree_entry_byindex,
	const Resource& tree,
	int64_t idx)
{
	const git_tree_entry *result;
	auto return_value = req::make<Git2Resource>();

	auto tree_ = dyn_cast<Git2Resource>(tree);

	result = git_tree_entry_byindex(HHVM_GIT2_V(tree_, tree), (size_t) idx);
	//HHVM_GIT2_V(return_value, tree_entry) = result; todo return as array
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_tree_entry_byoid,
	const Resource& tree,
	const String& oid)
{
	const git_tree_entry *result;
	auto return_value = req::make<Git2Resource>();

	git_oid oid_;

	auto tree_ = dyn_cast<Git2Resource>(tree);
	if (git_oid_fromstr(&oid_, oid.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}

	result = git_tree_entry_byoid(HHVM_GIT2_V(tree_, tree), &oid_);
	//HHVM_GIT2_V(return_value, tree_entry) = result; todo return as array
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_tree_entry_bypath,
	const Resource& root,
	const String& path)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_tree_entry *out = NULL;

	auto root_ = dyn_cast<Git2Resource>(root);

	result = git_tree_entry_bypath(&out, HHVM_GIT2_V(root_, tree), path.c_str());

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	HHVM_GIT2_V(return_value, tree_entry) = out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_tree_entry_dup,
	const Resource& entry)
{
	git_tree_entry *result;
	auto return_value = req::make<Git2Resource>();

	auto entry_ = dyn_cast<Git2Resource>(entry);

	result = git_tree_entry_dup(HHVM_GIT2_V(entry_, tree_entry));
	HHVM_GIT2_V(return_value, tree_entry) = result;
	return Resource(return_value);
}

void HHVM_FUNCTION(git_tree_entry_free,
	const Resource& entry)
{

	auto entry_ = dyn_cast<Git2Resource>(entry);

	git_tree_entry_free(HHVM_GIT2_V(entry_, tree_entry));
}

String HHVM_FUNCTION(git_tree_entry_name,
	const Resource& entry)
{
	const char *result;
	String return_value;

	auto entry_ = dyn_cast<Git2Resource>(entry);

	result = git_tree_entry_name(HHVM_GIT2_V(entry_, tree_entry));
	return_value = String(result);
	return return_value;
}

String HHVM_FUNCTION(git_tree_entry_id,
	const Resource& entry)
{
	const git_oid *result;
	char return_value[GIT_OID_HEXSZ+1] = {0};

	auto entry_ = dyn_cast<Git2Resource>(entry);

	result = git_tree_entry_id(HHVM_GIT2_V(entry_, tree_entry));
	git_oid_fmt(return_value, result);
	return String(return_value);
}

int64_t HHVM_FUNCTION(git_tree_entry_type,
	const Resource& entry)
{
	git_otype result;
	int64_t return_value;

	auto entry_ = dyn_cast<Git2Resource>(entry);

	result = git_tree_entry_type(HHVM_GIT2_V(entry_, tree_entry));
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_tree_entry_filemode,
	const Resource& entry)
{
	git_filemode_t result;
	int64_t return_value;

	auto entry_ = dyn_cast<Git2Resource>(entry);

	result = git_tree_entry_filemode(HHVM_GIT2_V(entry_, tree_entry));
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_tree_entry_filemode_raw,
	const Resource& entry)
{
	git_filemode_t result;
	int64_t return_value;

	auto entry_ = dyn_cast<Git2Resource>(entry);

	result = git_tree_entry_filemode_raw(HHVM_GIT2_V(entry_, tree_entry));
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_tree_entry_cmp,
	const Resource& e1,
	const Resource& e2)
{
	int result;
	int64_t return_value;

	auto e1_ = dyn_cast<Git2Resource>(e1);
	auto e2_ = dyn_cast<Git2Resource>(e2);

	result = git_tree_entry_cmp(HHVM_GIT2_V(e1_, tree_entry), HHVM_GIT2_V(e2_, tree_entry));

	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_tree_entry_to_object,
	const Resource& repo,
	const Resource& entry)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_object *object_out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto entry_ = dyn_cast<Git2Resource>(entry);

	result = git_tree_entry_to_object(&object_out, HHVM_GIT2_V(repo_, repository), HHVM_GIT2_V(entry_, tree_entry));

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	HHVM_GIT2_V(return_value, object) = object_out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_treebuilder_create,
	const Resource& source)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_treebuilder *out = NULL;

	auto source_ = dyn_cast<Git2Resource>(source);

	result = git_treebuilder_create(&out, HHVM_GIT2_V(source_, tree));

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	HHVM_GIT2_V(return_value, treebuilder) = out;
	return Resource(return_value);
}

void HHVM_FUNCTION(git_treebuilder_clear,
	const Resource& bld)
{

	auto bld_ = dyn_cast<Git2Resource>(bld);

	git_treebuilder_clear(HHVM_GIT2_V(bld_, treebuilder));
}

int64_t HHVM_FUNCTION(git_treebuilder_entrycount,
	const Resource& bld)
{
	int result;
	int64_t return_value;

	auto bld_ = dyn_cast<Git2Resource>(bld);

	result = git_treebuilder_entrycount(HHVM_GIT2_V(bld_, treebuilder));

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

void HHVM_FUNCTION(git_treebuilder_free,
	const Resource& bld)
{

	auto bld_ = dyn_cast<Git2Resource>(bld);

	git_treebuilder_free(HHVM_GIT2_V(bld_, treebuilder));
}

Resource HHVM_FUNCTION(git_treebuilder_get,
	const Resource& bld,
	const String& filename)
{
	const git_tree_entry *result;
	auto return_value = req::make<Git2Resource>();

	auto bld_ = dyn_cast<Git2Resource>(bld);

	result = git_treebuilder_get(HHVM_GIT2_V(bld_, treebuilder), filename.c_str());
	//HHVM_GIT2_V(return_value, tree_entry) = result; todo return as array
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_treebuilder_insert,
	const Resource& bld,
	const String& filename,
	const String& id,
	int64_t filemode)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	const git_tree_entry *out = NULL;
	git_oid id_;

	auto bld_ = dyn_cast<Git2Resource>(bld);
	if (git_oid_fromstr(&id_, id.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}

	result = git_treebuilder_insert(&out, HHVM_GIT2_V(bld_, treebuilder), filename.c_str(), &id_, (git_filemode_t) filemode);

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	//HHVM_GIT2_V(return_value, tree_entry) = out; todo return as array
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_treebuilder_remove,
	const Resource& bld,
	const String& filename)
{
	int result;
	int64_t return_value;

	auto bld_ = dyn_cast<Git2Resource>(bld);

	result = git_treebuilder_remove(HHVM_GIT2_V(bld_, treebuilder), filename.c_str());

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

void HHVM_FUNCTION(git_treebuilder_filter,
	const Resource& bld,
	const Variant& filter,
	const Variant& payload)
{

	git_treebuilder_filter_cb filter_ = NULL;
	void *payload_ = NULL;

	auto bld_ = dyn_cast<Git2Resource>(bld);
	filter_ = NULL;

	git_treebuilder_filter(HHVM_GIT2_V(bld_, treebuilder), /* todo */ filter_, payload_);
}

int64_t HHVM_FUNCTION(git_treebuilder_write,
	const String& id,
	const Resource& repo,
	const Resource& bld)
{
	int result;
	int64_t return_value;

	git_oid id_;

	if (git_oid_fromstr(&id_, id.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}
	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto bld_ = dyn_cast<Git2Resource>(bld);

	result = git_treebuilder_write(&id_, HHVM_GIT2_V(repo_, repository), HHVM_GIT2_V(bld_, treebuilder));

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_tree_walk,
	const Resource& tree,
	int64_t mode,
	const Variant& callback,
	const Variant& payload)
{
	int result;
	int64_t return_value;

	git_treewalk_cb callback_ = NULL;
	void *payload_ = NULL;

	auto tree_ = dyn_cast<Git2Resource>(tree);
	callback_ = NULL;

	result = git_tree_walk(HHVM_GIT2_V(tree_, tree), (git_treewalk_mode) mode, /* todo */ callback_, payload_);

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

