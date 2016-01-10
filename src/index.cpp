/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/system/systemlib.h"

#include "index.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_index_open,
	const String& index_path)
{
	auto return_value = req::make<Git2Resource>();

	git_index **out = NULL;

	git_index_open(out, index_path.c_str());
	HHVM_GIT2_V(return_value, index) = *out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_index_new)
{
	auto return_value = req::make<Git2Resource>();

	git_index **out = NULL;

	git_index_new(out);
	HHVM_GIT2_V(return_value, index) = *out;
	return Resource(return_value);
}

void HHVM_FUNCTION(git_index_free,
	const Resource& index)
{

	auto index_ = dyn_cast<Git2Resource>(index);

	git_index_free(HHVM_GIT2_V(index_, index));
}

Resource HHVM_FUNCTION(git_index_owner,
	const Resource& index)
{
	git_repository *result;
	auto return_value = req::make<Git2Resource>();

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_owner(HHVM_GIT2_V(index_, index));
	HHVM_GIT2_V(return_value, repository) = result;
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_index_caps,
	const Resource& index)
{
	int result;
	int64_t return_value;

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_caps(HHVM_GIT2_V(index_, index));
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_index_set_caps,
	const Resource& index,
	int64_t caps)
{
	int result;
	int64_t return_value;

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_set_caps(HHVM_GIT2_V(index_, index), (unsigned int) caps);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_index_read,
	const Resource& index,
	int64_t force)
{
	int result;
	int64_t return_value;

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_read(HHVM_GIT2_V(index_, index), (int) force);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_index_write,
	const Resource& index)
{
	int result;
	int64_t return_value;

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_write(HHVM_GIT2_V(index_, index));
	return_value = (int64_t) result;
	return return_value;
}

String HHVM_FUNCTION(git_index_path,
	const Resource& index)
{
	const char *result;
	String return_value;

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_path(HHVM_GIT2_V(index_, index));
	return_value = String(result);
	return return_value;
}

int64_t HHVM_FUNCTION(git_index_read_tree,
	const Resource& index,
	const Resource& tree)
{
	int result;
	int64_t return_value;

	auto index_ = dyn_cast<Git2Resource>(index);
	auto tree_ = dyn_cast<Git2Resource>(tree);

	result = git_index_read_tree(HHVM_GIT2_V(index_, index), HHVM_GIT2_V(tree_, tree));
	return_value = (int64_t) result;
	return return_value;
}

String HHVM_FUNCTION(git_index_write_tree,
	const Resource& index)
{
	char *return_value;

	git_oid *out = NULL;

	auto index_ = dyn_cast<Git2Resource>(index);

	git_index_write_tree(out, HHVM_GIT2_V(index_, index));
	git_oid_fmt(return_value, out);
	return String(return_value);
}

String HHVM_FUNCTION(git_index_write_tree_to,
	const Resource& index,
	const Resource& repo)
{
	char *return_value;

	git_oid *out = NULL;

	auto index_ = dyn_cast<Git2Resource>(index);
	auto repo_ = dyn_cast<Git2Resource>(repo);

	git_index_write_tree_to(out, HHVM_GIT2_V(index_, index), HHVM_GIT2_V(repo_, repository));
	git_oid_fmt(return_value, out);
	return String(return_value);
}

int64_t HHVM_FUNCTION(git_index_entrycount,
	const Resource& index)
{
	size_t result;
	int64_t return_value;

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_entrycount(HHVM_GIT2_V(index_, index));
	return_value = (int64_t) result;
	return return_value;
}

void HHVM_FUNCTION(git_index_clear,
	const Resource& index)
{

	auto index_ = dyn_cast<Git2Resource>(index);

	git_index_clear(HHVM_GIT2_V(index_, index));
}

Resource HHVM_FUNCTION(git_index_get_byindex,
	const Resource& index,
	int64_t n)
{
	const git_index_entry *result;
	auto return_value = req::make<Git2Resource>();

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_get_byindex(HHVM_GIT2_V(index_, index), (size_t) n);
	//HHVM_GIT2_V(return_value, index_entry) = result; todo return as array
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_index_get_bypath,
	const Resource& index,
	const String& path,
	int64_t stage)
{
	const git_index_entry *result;
	auto return_value = req::make<Git2Resource>();

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_get_bypath(HHVM_GIT2_V(index_, index), path.c_str(), (int) stage);
	//HHVM_GIT2_V(return_value, index_entry) = result; todo return as array
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_index_remove,
	const Resource& index,
	const String& path,
	int64_t stage)
{
	int result;
	int64_t return_value;

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_remove(HHVM_GIT2_V(index_, index), path.c_str(), (int) stage);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_index_remove_directory,
	const Resource& index,
	const String& dir,
	int64_t stage)
{
	int result;
	int64_t return_value;

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_remove_directory(HHVM_GIT2_V(index_, index), dir.c_str(), (int) stage);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_index_add,
	const Resource& index,
	const Resource& source_entry)
{
	int result;
	int64_t return_value;

	auto index_ = dyn_cast<Git2Resource>(index);
	auto source_entry_ = dyn_cast<Git2Resource>(source_entry);

	result = git_index_add(HHVM_GIT2_V(index_, index), HHVM_GIT2_V(source_entry_, index_entry));
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_index_entry_stage,
	const Resource& entry)
{
	int result;
	int64_t return_value;

	auto entry_ = dyn_cast<Git2Resource>(entry);

	result = git_index_entry_stage(HHVM_GIT2_V(entry_, index_entry));
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_index_add_bypath,
	const Resource& index,
	const String& path)
{
	int result;
	int64_t return_value;

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_add_bypath(HHVM_GIT2_V(index_, index), path.c_str());
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_index_remove_bypath,
	const Resource& index,
	const String& path)
{
	int result;
	int64_t return_value;

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_remove_bypath(HHVM_GIT2_V(index_, index), path.c_str());
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_index_add_all,
	const Resource& index,
	const Resource& pathspec,
	int64_t flags,
	const Variant& callback,
	const Variant& payload)
{
	int result;
	int64_t return_value;

	git_index_matched_path_cb callback_ = NULL;
	void *payload_ = NULL;

	auto index_ = dyn_cast<Git2Resource>(index);
	auto pathspec_ = dyn_cast<Git2Resource>(pathspec);
	callback_ = NULL;

	result = git_index_add_all(HHVM_GIT2_V(index_, index), HHVM_GIT2_V(pathspec_, strarray), (unsigned int) flags, /* todo */ callback_, payload_);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_index_remove_all,
	const Resource& index,
	const Resource& pathspec,
	const Variant& callback,
	const Variant& payload)
{
	int result;
	int64_t return_value;

	git_index_matched_path_cb callback_ = NULL;
	void *payload_ = NULL;

	auto index_ = dyn_cast<Git2Resource>(index);
	auto pathspec_ = dyn_cast<Git2Resource>(pathspec);
	callback_ = NULL;

	result = git_index_remove_all(HHVM_GIT2_V(index_, index), HHVM_GIT2_V(pathspec_, strarray), /* todo */ callback_, payload_);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_index_update_all,
	const Resource& index,
	const Resource& pathspec,
	const Variant& callback,
	const Variant& payload)
{
	int result;
	int64_t return_value;

	git_index_matched_path_cb callback_ = NULL;
	void *payload_ = NULL;

	auto index_ = dyn_cast<Git2Resource>(index);
	auto pathspec_ = dyn_cast<Git2Resource>(pathspec);
	callback_ = NULL;

	result = git_index_update_all(HHVM_GIT2_V(index_, index), HHVM_GIT2_V(pathspec_, strarray), /* todo */ callback_, payload_);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_index_find,
	int64_t at_pos,
	const Resource& index,
	const String& path)
{
	int result;
	int64_t return_value;

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_find((size_t*) at_pos, HHVM_GIT2_V(index_, index), path.c_str());
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_index_conflict_add,
	const Resource& index,
	const Resource& ancestor_entry,
	const Resource& our_entry,
	const Resource& their_entry)
{
	int result;
	int64_t return_value;

	auto index_ = dyn_cast<Git2Resource>(index);
	auto ancestor_entry_ = dyn_cast<Git2Resource>(ancestor_entry);
	auto our_entry_ = dyn_cast<Git2Resource>(our_entry);
	auto their_entry_ = dyn_cast<Git2Resource>(their_entry);

	result = git_index_conflict_add(HHVM_GIT2_V(index_, index), HHVM_GIT2_V(ancestor_entry_, index_entry), HHVM_GIT2_V(our_entry_, index_entry), HHVM_GIT2_V(their_entry_, index_entry));
	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_index_conflict_get,
	const Resource& index,
	const String& path)
{
	auto return_value = req::make<Git2Resource>();

	const git_index_entry **ancestor_out = NULL;
	const git_index_entry **our_out = NULL;
	const git_index_entry **their_out = NULL;

	auto index_ = dyn_cast<Git2Resource>(index);

	git_index_conflict_get(ancestor_out, our_out, their_out, HHVM_GIT2_V(index_, index), path.c_str());
	//HHVM_GIT2_V(return_value, index_entry) = *ancestor_out; todo return as array
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_index_conflict_remove,
	const Resource& index,
	const String& path)
{
	int result;
	int64_t return_value;

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_conflict_remove(HHVM_GIT2_V(index_, index), path.c_str());
	return_value = (int64_t) result;
	return return_value;
}

void HHVM_FUNCTION(git_index_conflict_cleanup,
	const Resource& index)
{

	auto index_ = dyn_cast<Git2Resource>(index);

	git_index_conflict_cleanup(HHVM_GIT2_V(index_, index));
}

int64_t HHVM_FUNCTION(git_index_has_conflicts,
	const Resource& index)
{
	int result;
	int64_t return_value;

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_has_conflicts(HHVM_GIT2_V(index_, index));
	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_index_conflict_iterator_new,
	const Resource& index)
{
	auto return_value = req::make<Git2Resource>();

	git_index_conflict_iterator **iterator_out = NULL;

	auto index_ = dyn_cast<Git2Resource>(index);

	git_index_conflict_iterator_new(iterator_out, HHVM_GIT2_V(index_, index));
	HHVM_GIT2_V(return_value, index_conflict_iterator) = *iterator_out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_index_conflict_next,
	const Resource& iterator)
{
	auto return_value = req::make<Git2Resource>();

	const git_index_entry **ancestor_out = NULL;
    const git_index_entry **our_out;
	const git_index_entry **their_out;

	auto iterator_ = dyn_cast<Git2Resource>(iterator);

	git_index_conflict_next(ancestor_out, our_out, their_out, HHVM_GIT2_V(iterator_, index_conflict_iterator));
	//HHVM_GIT2_V(return_value, index_entry) = *ancestor_out; todo return as array
	return Resource(return_value);
}

void HHVM_FUNCTION(git_index_conflict_iterator_free,
	const Resource& iterator)
{

	auto iterator_ = dyn_cast<Git2Resource>(iterator);

	git_index_conflict_iterator_free(HHVM_GIT2_V(iterator_, index_conflict_iterator));
}

