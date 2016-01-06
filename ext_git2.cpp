#include "hphp/runtime/ext/extension.h"
#include "ext_git2.h"

#include "src/attr.h"
#include "src/blame.h"
#include "src/blob.h"
#include "src/branch.h"
#include "src/buffer.h"
#include "src/checkout.h"
#include "src/clone.h"
#include "src/commit.h"
#include "src/common.h"
#include "src/config.h"
#include "src/cred_helpers.h"
#include "src/diff.h"
#include "src/errors.h"
#include "src/filter.h"
#include "src/graph.h"
#include "src/ignore.h"
#include "src/index.h"
#include "src/indexer.h"
#include "src/merge.h"
#include "src/message.h"
#include "src/notes.h"
#include "src/object.h"
#include "src/odb.h"
#include "src/odb_backend.h"
#include "src/oid.h"
#include "src/pack.h"
#include "src/patch.h"
#include "src/pathspec.h"
#include "src/push.h"
#include "src/refdb.h"
#include "src/reflog.h"
#include "src/refs.h"
#include "src/refspec.h"
#include "src/remote.h"
#include "src/repository.h"
#include "src/reset.h"
#include "src/revparse.h"
#include "src/revwalk.h"
#include "src/signature.h"
#include "src/stash.h"
#include "src/status.h"
#include "src/strarray.h"
#include "src/submodule.h"
#include "src/sys_commit.h"
#include "src/sys_config.h"
#include "src/sys_filter.h"
#include "src/sys_index.h"
#include "src/sys_odb_backend.h"
#include "src/sys_refdb_backend.h"
#include "src/sys_reflog.h"
#include "src/sys_refs.h"
#include "src/sys_repository.h"
#include "src/tag.h"
#include "src/threads.h"
#include "src/trace.h"
#include "src/transport.h"
#include "src/tree.h"
#define HHVM_RC_INT_SAME(const_name)                                \
Native::registerConstant<KindOfInt64>(                            \
makeStaticString(#const_name), (int64_t)const_name);
namespace HPHP {

static class Git2Extension : public Extension  {
  public:
    Git2Extension() : Extension("git2") {}
    virtual void moduleInit() {


      // --------------- attr.h ---------------
      HHVM_FE(git_attr_value);
      HHVM_FE(git_attr_get);
      HHVM_FE(git_attr_get_many);
      HHVM_FE(git_attr_foreach);
      HHVM_FE(git_attr_cache_flush);
      HHVM_FE(git_attr_add_macro);


      // --------------- blame.h ---------------
      HHVM_FE(git_blame_get_hunk_count);
      HHVM_FE(git_blame_get_hunk_byindex);
      HHVM_FE(git_blame_get_hunk_byline);
      HHVM_FE(git_blame_file);
      HHVM_FE(git_blame_buffer);
      HHVM_FE(git_blame_free);


      // --------------- blob.h ---------------
      HHVM_FE(git_blob_lookup);
      HHVM_FE(git_blob_lookup_prefix);
      HHVM_FE(git_blob_free);
      HHVM_FE(git_blob_id);
      HHVM_FE(git_blob_owner);
      HHVM_FE(git_blob_rawcontent);
      HHVM_FE(git_blob_rawsize);
      HHVM_FE(git_blob_filtered_content);
      HHVM_FE(git_blob_create_fromworkdir);
      HHVM_FE(git_blob_create_fromdisk);
      HHVM_FE(git_blob_create_fromchunks);
      HHVM_FE(git_blob_create_frombuffer);
      HHVM_FE(git_blob_is_binary);


      // --------------- branch.h ---------------
      HHVM_FE(git_branch_create);
      HHVM_FE(git_branch_delete);
      HHVM_FE(git_branch_iterator_new);
      HHVM_FE(git_branch_next);
      HHVM_FE(git_branch_iterator_free);
      HHVM_FE(git_branch_move);
      HHVM_FE(git_branch_lookup);
      HHVM_FE(git_branch_name);
      HHVM_FE(git_branch_upstream);
      HHVM_FE(git_branch_set_upstream);
      HHVM_FE(git_branch_upstream_name);
      HHVM_FE(git_branch_is_head);
      HHVM_FE(git_branch_remote_name);


      // --------------- buffer.h ---------------
      HHVM_FE(git_buf_free);
      HHVM_FE(git_buf_grow);
      HHVM_FE(git_buf_set);


      // --------------- checkout.h ---------------
      HHVM_FE(git_checkout_head);
      HHVM_FE(git_checkout_index);
      HHVM_FE(git_checkout_tree);


      // --------------- clone.h ---------------
      HHVM_FE(git_clone);
      HHVM_FE(git_clone_into);


      // --------------- commit.h ---------------
      HHVM_FE(git_commit_lookup);
      HHVM_FE(git_commit_lookup_prefix);
      HHVM_FE(git_commit_free);
      HHVM_FE(git_commit_id);
      HHVM_FE(git_commit_owner);
      HHVM_FE(git_commit_message_encoding);
      HHVM_FE(git_commit_message);
      HHVM_FE(git_commit_message_raw);
      HHVM_FE(git_commit_time);
      HHVM_FE(git_commit_time_offset);
      HHVM_FE(git_commit_committer);
      HHVM_FE(git_commit_author);
      HHVM_FE(git_commit_raw_header);
      HHVM_FE(git_commit_tree);
      HHVM_FE(git_commit_tree_id);
      HHVM_FE(git_commit_parentcount);
      HHVM_FE(git_commit_parent);
      HHVM_FE(git_commit_parent_id);
      HHVM_FE(git_commit_nth_gen_ancestor);
      HHVM_FE(git_commit_create);
        
      // todo
      //HHVM_FE(git_commit_create_v);


      // --------------- common.h ---------------
      HHVM_FE(git_libgit2_version);
        
      // todo
      //HHVM_FE(git_libgit2_capabilities);
      //HHVM_FE(git_libgit2_opts);


      // --------------- config.h ---------------
      HHVM_FE(git_config_find_global);
      HHVM_FE(git_config_find_xdg);
      HHVM_FE(git_config_find_system);
      HHVM_FE(git_config_add_file_ondisk);
      HHVM_FE(git_config_open_ondisk);
      HHVM_FE(git_config_open_level);
      HHVM_FE(git_config_open_global);
      HHVM_FE(git_config_refresh);
      HHVM_FE(git_config_free);
      HHVM_FE(git_config_get_entry);
      HHVM_FE(git_config_get_int32);
      HHVM_FE(git_config_get_int64);
      HHVM_FE(git_config_get_bool);
      HHVM_FE(git_config_get_string);
      HHVM_FE(git_config_get_multivar_foreach);
      HHVM_FE(git_config_multivar_iterator_new);
      HHVM_FE(git_config_next);
      HHVM_FE(git_config_iterator_free);
      HHVM_FE(git_config_set_int32);
      HHVM_FE(git_config_set_int64);
      HHVM_FE(git_config_set_bool);
      HHVM_FE(git_config_set_string);
      HHVM_FE(git_config_set_multivar);
      HHVM_FE(git_config_delete_entry);
      HHVM_FE(git_config_delete_multivar);
      HHVM_FE(git_config_foreach);
      HHVM_FE(git_config_iterator_new);
      HHVM_FE(git_config_iterator_glob_new);
      HHVM_FE(git_config_foreach_match);
      HHVM_FE(git_config_get_mapped);
      HHVM_FE(git_config_lookup_map_value);
      HHVM_FE(git_config_parse_bool);
      HHVM_FE(git_config_parse_int32);
      HHVM_FE(git_config_parse_int64);
        
      // todo
      //HHVM_FE(git_config_backend_foreach_match);


      // --------------- cred_helpers.h ---------------
      HHVM_FE(git_cred_userpass);


      // --------------- diff.h ---------------
      HHVM_FE(git_diff_free);
      /* todo
      HHVM_FE(git_diff_tree_to_tree);
      HHVM_FE(git_diff_tree_to_index);
      HHVM_FE(git_diff_index_to_workdir);
      HHVM_FE(git_diff_tree_to_workdir);
      HHVM_FE(git_diff_tree_to_workdir_with_index); */
      HHVM_FE(git_diff_merge);
      HHVM_FE(git_diff_find_similar);
      HHVM_FE(git_diff_options_init);
      HHVM_FE(git_diff_num_deltas);
      HHVM_FE(git_diff_num_deltas_of_type);
      HHVM_FE(git_diff_get_delta);
      HHVM_FE(git_diff_is_sorted_icase);
      HHVM_FE(git_diff_foreach);
      HHVM_FE(git_diff_status_char);
      HHVM_FE(git_diff_print);
      HHVM_FE(git_diff_blobs);
      HHVM_FE(git_diff_blob_to_buffer);


      // --------------- errors.h ---------------
      HHVM_FE(giterr_last);
      HHVM_FE(giterr_clear);
      HHVM_FE(giterr_detach);
      HHVM_FE(giterr_set_str);
      HHVM_FE(giterr_set_oom);


      // --------------- filter.h ---------------
      HHVM_FE(git_filter_list_load);
      HHVM_FE(git_filter_list_apply_to_data);
      HHVM_FE(git_filter_list_apply_to_file);
      HHVM_FE(git_filter_list_apply_to_blob);
      HHVM_FE(git_filter_list_free);


      // --------------- graph.h ---------------
      HHVM_FE(git_graph_ahead_behind);


      // --------------- ignore.h ---------------
      HHVM_FE(git_ignore_add_rule);
      HHVM_FE(git_ignore_clear_internal_rules);
      HHVM_FE(git_ignore_path_is_ignored);


      // --------------- index.h ---------------
      HHVM_FE(git_index_open);
      HHVM_FE(git_index_free);
      HHVM_FE(git_index_owner);
      HHVM_FE(git_index_caps);
      HHVM_FE(git_index_set_caps);
      HHVM_FE(git_index_read);
      HHVM_FE(git_index_write);
      HHVM_FE(git_index_path);
      HHVM_FE(git_index_read_tree);
      HHVM_FE(git_index_write_tree);
      HHVM_FE(git_index_write_tree_to);
      HHVM_FE(git_index_entrycount);
      HHVM_FE(git_index_clear);
      HHVM_FE(git_index_get_byindex);
      HHVM_FE(git_index_get_bypath);
      HHVM_FE(git_index_remove);
      HHVM_FE(git_index_remove_directory);
      HHVM_FE(git_index_add);
      HHVM_FE(git_index_entry_stage);
      HHVM_FE(git_index_add_bypath);
      HHVM_FE(git_index_remove_bypath);
      HHVM_FE(git_index_add_all);
      HHVM_FE(git_index_remove_all);
      HHVM_FE(git_index_update_all);
      HHVM_FE(git_index_find);
      HHVM_FE(git_index_conflict_add);
      HHVM_FE(git_index_conflict_get);
      HHVM_FE(git_index_conflict_remove);
      HHVM_FE(git_index_conflict_cleanup);
      HHVM_FE(git_index_has_conflicts);
      HHVM_FE(git_index_conflict_iterator_new);
      HHVM_FE(git_index_conflict_next);
      HHVM_FE(git_index_conflict_iterator_free);


      // --------------- indexer.h ---------------
      HHVM_FE(git_indexer_new);
      HHVM_FE(git_indexer_append);
      HHVM_FE(git_indexer_commit);
      HHVM_FE(git_indexer_hash);
      HHVM_FE(git_indexer_free);


      // --------------- merge.h ---------------
      HHVM_FE(git_merge_base);
      HHVM_FE(git_merge_base_many);
      HHVM_FE(git_merge_head_from_ref);
      HHVM_FE(git_merge_head_from_fetchhead);
      HHVM_FE(git_merge_head_from_oid);
      HHVM_FE(git_merge_head_free);
      HHVM_FE(git_merge_trees);
      HHVM_FE(git_merge);
      HHVM_FE(git_merge_result_is_uptodate);
      HHVM_FE(git_merge_result_is_fastforward);
      HHVM_FE(git_merge_result_fastforward_oid);
      HHVM_FE(git_merge_result_free);


      // --------------- message.h ---------------
      HHVM_FE(git_message_prettify);


      // --------------- notes.h ---------------
      HHVM_FE(git_note_iterator_new);
      HHVM_FE(git_note_iterator_free);
      HHVM_FE(git_note_next);
      HHVM_FE(git_note_read);
      HHVM_FE(git_note_message);
      HHVM_FE(git_note_oid);
      HHVM_FE(git_note_create);
      HHVM_FE(git_note_remove);
      HHVM_FE(git_note_free);
      HHVM_FE(git_note_default_ref);
      HHVM_FE(git_note_foreach);


      // --------------- object.h ---------------
      HHVM_FE(git_object_lookup);
      HHVM_FE(git_object_lookup_prefix);
      HHVM_FE(git_object_lookup_bypath);
      HHVM_FE(git_object_id);
      HHVM_FE(git_object_type);
      HHVM_FE(git_object_owner);
      HHVM_FE(git_object_free);
      HHVM_FE(git_object_type2string);
      HHVM_FE(git_object_string2type);
      HHVM_FE(git_object_typeisloose);
      HHVM_FE(git_object__size);
      HHVM_FE(git_object_peel);
      HHVM_FE(git_object_dup);


      // --------------- odb.h ---------------
      HHVM_FE(git_odb_open);
      HHVM_FE(git_odb_add_disk_alternate);
      HHVM_FE(git_odb_free);
      HHVM_FE(git_odb_read);
      HHVM_FE(git_odb_read_prefix);
      HHVM_FE(git_odb_read_header);
      HHVM_FE(git_odb_exists);
      HHVM_FE(git_odb_refresh);
      HHVM_FE(git_odb_foreach);
      HHVM_FE(git_odb_write);
      HHVM_FE(git_odb_open_wstream);
      HHVM_FE(git_odb_stream_write);
      HHVM_FE(git_odb_stream_finalize_write);
      HHVM_FE(git_odb_stream_read);
      HHVM_FE(git_odb_stream_free);
      HHVM_FE(git_odb_open_rstream);
      HHVM_FE(git_odb_write_pack);
      HHVM_FE(git_odb_hash);
      HHVM_FE(git_odb_hashfile);
      HHVM_FE(git_odb_object_dup);
      HHVM_FE(git_odb_object_free);
      HHVM_FE(git_odb_object_id);
      HHVM_FE(git_odb_object_data);
      HHVM_FE(git_odb_object_size);
      HHVM_FE(git_odb_object_type);
      HHVM_FE(git_odb_add_backend);
      HHVM_FE(git_odb_add_alternate);
      HHVM_FE(git_odb_num_backends);
      HHVM_FE(git_odb_get_backend);


      // --------------- odb_backend.h ---------------
      HHVM_FE(git_odb_backend_pack);
      HHVM_FE(git_odb_backend_loose);
      HHVM_FE(git_odb_backend_one_pack);


      // --------------- oid.h ---------------
      HHVM_FE(git_oid_fromstr);
      HHVM_FE(git_oid_fromstrp);
      HHVM_FE(git_oid_fromstrn);
      HHVM_FE(git_oid_fromraw);
      HHVM_FE(git_oid_fmt);
      HHVM_FE(git_oid_nfmt);
      HHVM_FE(git_oid_pathfmt);
      HHVM_FE(git_oid_allocfmt);
      HHVM_FE(git_oid_tostr);
      HHVM_FE(git_oid_cpy);
      HHVM_FE(git_oid_cmp);
      HHVM_FE(git_oid_ncmp);
      HHVM_FE(git_oid_streq);
      HHVM_FE(git_oid_strcmp);
      HHVM_FE(git_oid_iszero);
      HHVM_FE(git_oid_shorten_new);
      HHVM_FE(git_oid_shorten_add);
      HHVM_FE(git_oid_shorten_free);


      // --------------- pack.h ---------------
      HHVM_FE(git_packbuilder_new);
      HHVM_FE(git_packbuilder_set_threads);
      HHVM_FE(git_packbuilder_insert);
      HHVM_FE(git_packbuilder_insert_tree);
      HHVM_FE(git_packbuilder_insert_commit);
      HHVM_FE(git_packbuilder_write);
      HHVM_FE(git_packbuilder_hash);
      HHVM_FE(git_packbuilder_foreach);
      HHVM_FE(git_packbuilder_object_count);
      HHVM_FE(git_packbuilder_written);
      HHVM_FE(git_packbuilder_set_callbacks);
      HHVM_FE(git_packbuilder_free);


      // --------------- patch.h ---------------
      HHVM_FE(git_patch_from_diff);
      HHVM_FE(git_patch_from_blobs);
      HHVM_FE(git_patch_from_blob_and_buffer);
      HHVM_FE(git_patch_free);
      HHVM_FE(git_patch_get_delta);
      HHVM_FE(git_patch_num_hunks);
      HHVM_FE(git_patch_line_stats);
      HHVM_FE(git_patch_get_hunk);
      HHVM_FE(git_patch_num_lines_in_hunk);
      HHVM_FE(git_patch_get_line_in_hunk);
      HHVM_FE(git_patch_size);
      HHVM_FE(git_patch_print);
      HHVM_FE(git_patch_to_str);


      // --------------- pathspec.h ---------------
      HHVM_FE(git_pathspec_new);
      HHVM_FE(git_pathspec_free);
      HHVM_FE(git_pathspec_matches_path);
      HHVM_FE(git_pathspec_match_workdir);
      HHVM_FE(git_pathspec_match_index);
      HHVM_FE(git_pathspec_match_tree);
      HHVM_FE(git_pathspec_match_diff);
      HHVM_FE(git_pathspec_match_list_free);
      HHVM_FE(git_pathspec_match_list_entrycount);
      HHVM_FE(git_pathspec_match_list_entry);
      HHVM_FE(git_pathspec_match_list_diff_entry);
      HHVM_FE(git_pathspec_match_list_failed_entrycount);
      HHVM_FE(git_pathspec_match_list_failed_entry);


      // --------------- push.h ---------------
      HHVM_FE(git_push_new);
      HHVM_FE(git_push_set_options);
      HHVM_FE(git_push_set_callbacks);
      HHVM_FE(git_push_add_refspec);
      HHVM_FE(git_push_update_tips);
      HHVM_FE(git_push_finish);
      HHVM_FE(git_push_unpack_ok);
      HHVM_FE(git_push_status_foreach);
      HHVM_FE(git_push_free);


      // --------------- refdb.h ---------------
      HHVM_FE(git_refdb_new);
      HHVM_FE(git_refdb_open);
      HHVM_FE(git_refdb_compress);
      HHVM_FE(git_refdb_free);


      // --------------- reflog.h ---------------
      HHVM_FE(git_reflog_read);
      HHVM_FE(git_reflog_write);
      HHVM_FE(git_reflog_append);
      HHVM_FE(git_reflog_append_to);
      HHVM_FE(git_reflog_rename);
      HHVM_FE(git_reflog_delete);
      HHVM_FE(git_reflog_entrycount);
      HHVM_FE(git_reflog_entry_byindex);
      HHVM_FE(git_reflog_drop);
      HHVM_FE(git_reflog_entry_id_old);
      HHVM_FE(git_reflog_entry_id_new);
      HHVM_FE(git_reflog_entry_committer);
      HHVM_FE(git_reflog_entry_message);
      HHVM_FE(git_reflog_free);


      // --------------- refs.h ---------------
      HHVM_FE(git_reference_lookup);
      HHVM_FE(git_reference_name_to_id);
      HHVM_FE(git_reference_dwim);
      HHVM_FE(git_reference_symbolic_create);
      HHVM_FE(git_reference_create);
      HHVM_FE(git_reference_target);
      HHVM_FE(git_reference_target_peel);
      HHVM_FE(git_reference_symbolic_target);
      HHVM_FE(git_reference_type);
      HHVM_FE(git_reference_name);
      HHVM_FE(git_reference_resolve);
      HHVM_FE(git_reference_owner);
      HHVM_FE(git_reference_symbolic_set_target);
      HHVM_FE(git_reference_set_target);
      HHVM_FE(git_reference_rename);
      HHVM_FE(git_reference_delete);
      HHVM_FE(git_reference_list);
      HHVM_FE(git_reference_foreach);
      HHVM_FE(git_reference_foreach_name);
      HHVM_FE(git_reference_free);
      HHVM_FE(git_reference_cmp);
      HHVM_FE(git_reference_iterator_new);
      HHVM_FE(git_reference_iterator_glob_new);
      HHVM_FE(git_reference_next);
      HHVM_FE(git_reference_next_name);
      HHVM_FE(git_reference_iterator_free);
      HHVM_FE(git_reference_foreach_glob);
      HHVM_FE(git_reference_has_log);
      HHVM_FE(git_reference_is_branch);
      HHVM_FE(git_reference_is_remote);
      HHVM_FE(git_reference_is_tag);
      HHVM_FE(git_reference_normalize_name);
      HHVM_FE(git_reference_peel);
      HHVM_FE(git_reference_is_valid_name);
      HHVM_FE(git_reference_shorthand);


      // --------------- refspec.h ---------------
      HHVM_FE(git_refspec_src);
      HHVM_FE(git_refspec_dst);
      HHVM_FE(git_refspec_string);
      HHVM_FE(git_refspec_force);
      HHVM_FE(git_refspec_direction);
      HHVM_FE(git_refspec_src_matches);
      HHVM_FE(git_refspec_dst_matches);
      HHVM_FE(git_refspec_transform);
      HHVM_FE(git_refspec_rtransform);


      // --------------- remote.h ---------------
      HHVM_FE(git_remote_create);
      HHVM_FE(git_remote_create_with_fetchspec);
      HHVM_FE(git_remote_create_inmemory);
      HHVM_FE(git_remote_load);
      HHVM_FE(git_remote_save);
      HHVM_FE(git_remote_owner);
      HHVM_FE(git_remote_name);
      HHVM_FE(git_remote_url);
      HHVM_FE(git_remote_pushurl);
      HHVM_FE(git_remote_set_url);
      HHVM_FE(git_remote_set_pushurl);
      HHVM_FE(git_remote_add_fetch);
      HHVM_FE(git_remote_get_fetch_refspecs);
      HHVM_FE(git_remote_set_fetch_refspecs);
      HHVM_FE(git_remote_add_push);
      HHVM_FE(git_remote_get_push_refspecs);
      HHVM_FE(git_remote_set_push_refspecs);
      HHVM_FE(git_remote_clear_refspecs);
      HHVM_FE(git_remote_refspec_count);
      HHVM_FE(git_remote_get_refspec);
      HHVM_FE(git_remote_connect);
      HHVM_FE(git_remote_ls);
      HHVM_FE(git_remote_download);
      HHVM_FE(git_remote_connected);
      HHVM_FE(git_remote_stop);
      HHVM_FE(git_remote_disconnect);
      HHVM_FE(git_remote_free);
      HHVM_FE(git_remote_update_tips);
      HHVM_FE(git_remote_fetch);
      HHVM_FE(git_remote_valid_url);
      HHVM_FE(git_remote_supported_url);
      HHVM_FE(git_remote_list);
      HHVM_FE(git_remote_check_cert);
      HHVM_FE(git_remote_set_transport);
      HHVM_FE(git_remote_set_callbacks);
      HHVM_FE(git_remote_stats);
      HHVM_FE(git_remote_autotag);
      HHVM_FE(git_remote_set_autotag);
      HHVM_FE(git_remote_rename);
      HHVM_FE(git_remote_update_fetchhead);
      HHVM_FE(git_remote_set_update_fetchhead);
      HHVM_FE(git_remote_is_valid_name);


      // --------------- repository.h ---------------
      HHVM_FE(git_repository_open);
      HHVM_FE(git_repository_wrap_odb);
      HHVM_FE(git_repository_discover);
      HHVM_FE(git_repository_open_ext);
      HHVM_FE(git_repository_open_bare);
      HHVM_FE(git_repository_free);
      HHVM_FE(git_repository_init);
      HHVM_FE(git_repository_init_ext);
      HHVM_FE(git_repository_head);
      HHVM_FE(git_repository_head_detached);
      HHVM_FE(git_repository_head_unborn);
      HHVM_FE(git_repository_is_empty);
      HHVM_FE(git_repository_path);
      HHVM_FE(git_repository_workdir);
      HHVM_FE(git_repository_set_workdir);
      HHVM_FE(git_repository_is_bare);
      HHVM_FE(git_repository_config);
      HHVM_FE(git_repository_odb);
      HHVM_FE(git_repository_refdb);
      HHVM_FE(git_repository_index);
      HHVM_FE(git_repository_message);
      HHVM_FE(git_repository_message_remove);
      HHVM_FE(git_repository_merge_cleanup);
      HHVM_FE(git_repository_fetchhead_foreach);
      HHVM_FE(git_repository_mergehead_foreach);
      HHVM_FE(git_repository_hashfile);
      HHVM_FE(git_repository_set_head);
      HHVM_FE(git_repository_set_head_detached);
      HHVM_FE(git_repository_detach_head);
      HHVM_FE(git_repository_state);
      HHVM_FE(git_repository_set_namespace);
      HHVM_FE(git_repository_get_namespace);
      HHVM_FE(git_repository_is_shallow);


      // --------------- reset.h ---------------
      HHVM_FE(git_reset);
      HHVM_FE(git_reset_default);


      // --------------- revparse.h ---------------
      HHVM_FE(git_revparse_single);
      HHVM_FE(git_revparse_ext);
      HHVM_FE(git_revparse);


      // --------------- revwalk.h ---------------
      HHVM_FE(git_revwalk_new);
      HHVM_FE(git_revwalk_reset);
      HHVM_FE(git_revwalk_push);
      HHVM_FE(git_revwalk_push_glob);
      HHVM_FE(git_revwalk_push_head);
      HHVM_FE(git_revwalk_hide);
      HHVM_FE(git_revwalk_hide_glob);
      HHVM_FE(git_revwalk_hide_head);
      HHVM_FE(git_revwalk_push_ref);
      HHVM_FE(git_revwalk_hide_ref);
      HHVM_FE(git_revwalk_next);
      HHVM_FE(git_revwalk_sorting);
      HHVM_FE(git_revwalk_push_range);
      HHVM_FE(git_revwalk_simplify_first_parent);
      HHVM_FE(git_revwalk_free);
      HHVM_FE(git_revwalk_repository);


      // --------------- signature.h ---------------
      HHVM_FE(git_signature_new);
      HHVM_FE(git_signature_now);
      HHVM_FE(git_signature_default);
      HHVM_FE(git_signature_dup);
      HHVM_FE(git_signature_free);


      // --------------- stash.h ---------------
      HHVM_FE(git_stash_save);
      HHVM_FE(git_stash_foreach);
      HHVM_FE(git_stash_drop);


      // --------------- status.h ---------------
      HHVM_FE(git_status_foreach);
      HHVM_FE(git_status_foreach_ext);
      HHVM_FE(git_status_file);
      HHVM_FE(git_status_list_new);
      HHVM_FE(git_status_list_entrycount);
      HHVM_FE(git_status_byindex);
      HHVM_FE(git_status_list_free);
      HHVM_FE(git_status_should_ignore);


      // --------------- strarray.h ---------------
      HHVM_FE(git_strarray_free);
      HHVM_FE(git_strarray_copy);


      // --------------- submodule.h ---------------
      HHVM_FE(git_submodule_lookup);
      HHVM_FE(git_submodule_foreach);
      HHVM_FE(git_submodule_add_setup);
      HHVM_FE(git_submodule_add_finalize);
      HHVM_FE(git_submodule_add_to_index);
      HHVM_FE(git_submodule_save);
      HHVM_FE(git_submodule_owner);
      HHVM_FE(git_submodule_name);
      HHVM_FE(git_submodule_path);
      HHVM_FE(git_submodule_url);
      HHVM_FE(git_submodule_set_url);
      HHVM_FE(git_submodule_index_id);
      HHVM_FE(git_submodule_head_id);
      HHVM_FE(git_submodule_wd_id);
      HHVM_FE(git_submodule_ignore);
      HHVM_FE(git_submodule_set_ignore);
      HHVM_FE(git_submodule_update);
      HHVM_FE(git_submodule_set_update);
      HHVM_FE(git_submodule_fetch_recurse_submodules);
      HHVM_FE(git_submodule_set_fetch_recurse_submodules);
      HHVM_FE(git_submodule_init);
      HHVM_FE(git_submodule_sync);
      HHVM_FE(git_submodule_open);
      HHVM_FE(git_submodule_reload);
      HHVM_FE(git_submodule_reload_all);
      HHVM_FE(git_submodule_status);
      HHVM_FE(git_submodule_location);


      // --------------- sys_commit.h ---------------
      HHVM_FE(git_commit_create_from_oids);


      // --------------- sys_config.h ---------------
      HHVM_FE(git_config_add_backend);


      // --------------- sys_filter.h ---------------
      HHVM_FE(git_filter_lookup);
      HHVM_FE(git_filter_list_new);
      HHVM_FE(git_filter_list_push);
      HHVM_FE(git_filter_list_length);
      HHVM_FE(git_filter_source_repo);
      HHVM_FE(git_filter_source_path);
      HHVM_FE(git_filter_source_filemode);
      HHVM_FE(git_filter_source_id);
      HHVM_FE(git_filter_source_mode);
      HHVM_FE(git_filter_register);
      HHVM_FE(git_filter_unregister);


      // --------------- sys_index.h ---------------
      HHVM_FE(git_index_name_entrycount);
      HHVM_FE(git_index_name_get_byindex);
      HHVM_FE(git_index_name_add);
      HHVM_FE(git_index_name_clear);
      HHVM_FE(git_index_reuc_entrycount);
      HHVM_FE(git_index_reuc_find);
      HHVM_FE(git_index_reuc_get_bypath);
      HHVM_FE(git_index_reuc_get_byindex);
      HHVM_FE(git_index_reuc_add);
      HHVM_FE(git_index_reuc_remove);
      HHVM_FE(git_index_reuc_clear);


      // --------------- sys_odb_backend.h ---------------
      HHVM_FE(git_odb_backend_malloc);


      // --------------- sys_refdb_backend.h ---------------
      HHVM_FE(git_refdb_backend_fs);
      HHVM_FE(git_refdb_set_backend);


      // --------------- sys_reflog.h ---------------
      HHVM_FE(git_reflog_entry__alloc);
      HHVM_FE(git_reflog_entry__free);


      // --------------- sys_refs.h ---------------
      HHVM_FE(git_reference__alloc);
      HHVM_FE(git_reference__alloc_symbolic);


      // --------------- sys_repository.h ---------------
      HHVM_FE(git_repository__cleanup);
      HHVM_FE(git_repository_reinit_filesystem);
      HHVM_FE(git_repository_set_config);
      HHVM_FE(git_repository_set_odb);
      HHVM_FE(git_repository_set_refdb);
      HHVM_FE(git_repository_set_index);


      // --------------- tag.h ---------------
      HHVM_FE(git_tag_lookup);
      HHVM_FE(git_tag_lookup_prefix);
      HHVM_FE(git_tag_free);
      HHVM_FE(git_tag_id);
      HHVM_FE(git_tag_owner);
      HHVM_FE(git_tag_target);
      HHVM_FE(git_tag_target_id);
      HHVM_FE(git_tag_target_type);
      HHVM_FE(git_tag_name);
      HHVM_FE(git_tag_tagger);
      HHVM_FE(git_tag_message);
      HHVM_FE(git_tag_create);
      HHVM_FE(git_tag_annotation_create);
      HHVM_FE(git_tag_create_frombuffer);
      HHVM_FE(git_tag_create_lightweight);
      HHVM_FE(git_tag_delete);
      HHVM_FE(git_tag_list);
      HHVM_FE(git_tag_list_match);
      HHVM_FE(git_tag_foreach);
      HHVM_FE(git_tag_peel);


      // --------------- threads.h ---------------
      HHVM_FE(git_threads_init);
      HHVM_FE(git_threads_shutdown);


      // --------------- trace.h ---------------
      HHVM_FE(git_trace_set);


      // --------------- transport.h ---------------
      HHVM_FE(git_cred_has_username);
      HHVM_FE(git_cred_userpass_plaintext_new);
      HHVM_FE(git_cred_ssh_key_new);
      HHVM_FE(git_cred_ssh_custom_new);
      HHVM_FE(git_transport_new);
      HHVM_FE(git_transport_register);
      HHVM_FE(git_transport_unregister);
      HHVM_FE(git_transport_dummy);
      HHVM_FE(git_transport_local);
      HHVM_FE(git_transport_smart);
      HHVM_FE(git_smart_subtransport_http);
      HHVM_FE(git_smart_subtransport_git);
      HHVM_FE(git_smart_subtransport_ssh);


      // --------------- tree.h ---------------
      HHVM_FE(git_tree_lookup);
      HHVM_FE(git_tree_lookup_prefix);
      HHVM_FE(git_tree_free);
      HHVM_FE(git_tree_id);
      HHVM_FE(git_tree_owner);
      HHVM_FE(git_tree_entrycount);
      HHVM_FE(git_tree_entry_byname);
      HHVM_FE(git_tree_entry_byindex);
      HHVM_FE(git_tree_entry_byoid);
      HHVM_FE(git_tree_entry_bypath);
      HHVM_FE(git_tree_entry_dup);
      HHVM_FE(git_tree_entry_free);
      HHVM_FE(git_tree_entry_name);
      HHVM_FE(git_tree_entry_id);
      HHVM_FE(git_tree_entry_type);
      HHVM_FE(git_tree_entry_filemode);
      HHVM_FE(git_tree_entry_filemode_raw);
      HHVM_FE(git_tree_entry_cmp);
      HHVM_FE(git_tree_entry_to_object);
      HHVM_FE(git_treebuilder_create);
      HHVM_FE(git_treebuilder_clear);
      HHVM_FE(git_treebuilder_entrycount);
      HHVM_FE(git_treebuilder_free);
      HHVM_FE(git_treebuilder_get);
      HHVM_FE(git_treebuilder_insert);
      HHVM_FE(git_treebuilder_remove);
      HHVM_FE(git_treebuilder_filter);
      HHVM_FE(git_treebuilder_write);
      HHVM_FE(git_tree_walk);


      /*            ---- CONSTANTS ----
       * register constants of all known enums in libgit2
       * todo: register only necessary constants!!!
       */


      // --------------- attr.h ---------------

      // --------------- git_attr_t ---------------
      HHVM_RC_INT_SAME(GIT_ATTR_UNSPECIFIED_T);
      HHVM_RC_INT_SAME(GIT_ATTR_TRUE_T);
      HHVM_RC_INT_SAME(GIT_ATTR_FALSE_T);
      HHVM_RC_INT_SAME(GIT_ATTR_VALUE_T);


      // --------------- blame.h ---------------

      // --------------- git_blame_flag_t ---------------
      HHVM_RC_INT_SAME(GIT_BLAME_NORMAL);
      HHVM_RC_INT_SAME(GIT_BLAME_TRACK_COPIES_SAME_FILE);
      HHVM_RC_INT_SAME(GIT_BLAME_TRACK_COPIES_SAME_COMMIT_MOVES);
      HHVM_RC_INT_SAME(GIT_BLAME_TRACK_COPIES_SAME_COMMIT_COPIES);
      HHVM_RC_INT_SAME(GIT_BLAME_TRACK_COPIES_ANY_COMMIT_COPIES);


      // --------------- checkout.h ---------------

      // --------------- git_checkout_strategy_t ---------------
      HHVM_RC_INT_SAME(GIT_CHECKOUT_NONE);
      HHVM_RC_INT_SAME(GIT_CHECKOUT_SAFE);
      HHVM_RC_INT_SAME(GIT_CHECKOUT_SAFE_CREATE);
      HHVM_RC_INT_SAME(GIT_CHECKOUT_FORCE);
      HHVM_RC_INT_SAME(GIT_CHECKOUT_ALLOW_CONFLICTS);
      HHVM_RC_INT_SAME(GIT_CHECKOUT_REMOVE_UNTRACKED);
      HHVM_RC_INT_SAME(GIT_CHECKOUT_REMOVE_IGNORED);
      HHVM_RC_INT_SAME(GIT_CHECKOUT_UPDATE_ONLY);
      HHVM_RC_INT_SAME(GIT_CHECKOUT_DONT_UPDATE_INDEX);
      HHVM_RC_INT_SAME(GIT_CHECKOUT_NO_REFRESH);
      HHVM_RC_INT_SAME(GIT_CHECKOUT_SKIP_UNMERGED);
      HHVM_RC_INT_SAME(GIT_CHECKOUT_USE_OURS);
      HHVM_RC_INT_SAME(GIT_CHECKOUT_USE_THEIRS);
      HHVM_RC_INT_SAME(GIT_CHECKOUT_DISABLE_PATHSPEC_MATCH);
      HHVM_RC_INT_SAME(GIT_CHECKOUT_SKIP_LOCKED_DIRECTORIES);
      HHVM_RC_INT_SAME(GIT_CHECKOUT_UPDATE_SUBMODULES);
      HHVM_RC_INT_SAME(GIT_CHECKOUT_UPDATE_SUBMODULES_IF_CHANGED);

      // --------------- git_checkout_notify_t ---------------
      HHVM_RC_INT_SAME(GIT_CHECKOUT_NOTIFY_NONE);
      HHVM_RC_INT_SAME(GIT_CHECKOUT_NOTIFY_CONFLICT);
      HHVM_RC_INT_SAME(GIT_CHECKOUT_NOTIFY_DIRTY);
      HHVM_RC_INT_SAME(GIT_CHECKOUT_NOTIFY_UPDATED);
      HHVM_RC_INT_SAME(GIT_CHECKOUT_NOTIFY_UNTRACKED);
      HHVM_RC_INT_SAME(GIT_CHECKOUT_NOTIFY_IGNORED);
      HHVM_RC_INT_SAME(GIT_CHECKOUT_NOTIFY_ALL);


      // --------------- common.h ---------------

      // --------------- git_cap_t ---------------
      HHVM_RC_INT_SAME(GIT_CAP_THREADS);
      HHVM_RC_INT_SAME(GIT_CAP_HTTPS);
      HHVM_RC_INT_SAME(GIT_CAP_SSH);

      // --------------- git_libgit2_opt_t ---------------
      HHVM_RC_INT_SAME(GIT_OPT_GET_MWINDOW_SIZE);
      HHVM_RC_INT_SAME(GIT_OPT_SET_MWINDOW_SIZE);
      HHVM_RC_INT_SAME(GIT_OPT_GET_MWINDOW_MAPPED_LIMIT);
      HHVM_RC_INT_SAME(GIT_OPT_SET_MWINDOW_MAPPED_LIMIT);
      HHVM_RC_INT_SAME(GIT_OPT_GET_SEARCH_PATH);
      HHVM_RC_INT_SAME(GIT_OPT_SET_SEARCH_PATH);
      HHVM_RC_INT_SAME(GIT_OPT_SET_CACHE_OBJECT_LIMIT);
      HHVM_RC_INT_SAME(GIT_OPT_SET_CACHE_MAX_SIZE);
      HHVM_RC_INT_SAME(GIT_OPT_ENABLE_CACHING);
      HHVM_RC_INT_SAME(GIT_OPT_GET_CACHED_MEMORY);
      HHVM_RC_INT_SAME(GIT_OPT_GET_TEMPLATE_PATH);
      HHVM_RC_INT_SAME(GIT_OPT_SET_TEMPLATE_PATH);


      // --------------- config.h ---------------

      // --------------- git_config_level_t ---------------
      HHVM_RC_INT_SAME(GIT_CONFIG_LEVEL_SYSTEM);
      HHVM_RC_INT_SAME(GIT_CONFIG_LEVEL_XDG);
      HHVM_RC_INT_SAME(GIT_CONFIG_LEVEL_GLOBAL);
      HHVM_RC_INT_SAME(GIT_CONFIG_LEVEL_LOCAL);
      HHVM_RC_INT_SAME(GIT_CONFIG_LEVEL_APP);
      HHVM_RC_INT_SAME(GIT_CONFIG_HIGHEST_LEVEL);

      // --------------- git_cvar_t ---------------
      HHVM_RC_INT_SAME(GIT_CVAR_FALSE);
      HHVM_RC_INT_SAME(GIT_CVAR_TRUE);
      HHVM_RC_INT_SAME(GIT_CVAR_INT32);
      HHVM_RC_INT_SAME(GIT_CVAR_STRING);


      // --------------- diff.h ---------------

      // --------------- git_diff_option_t ---------------
      HHVM_RC_INT_SAME(GIT_DIFF_NORMAL);
      HHVM_RC_INT_SAME(GIT_DIFF_REVERSE);
      HHVM_RC_INT_SAME(GIT_DIFF_INCLUDE_IGNORED);
      HHVM_RC_INT_SAME(GIT_DIFF_RECURSE_IGNORED_DIRS);
      HHVM_RC_INT_SAME(GIT_DIFF_INCLUDE_UNTRACKED);
      HHVM_RC_INT_SAME(GIT_DIFF_RECURSE_UNTRACKED_DIRS);
      HHVM_RC_INT_SAME(GIT_DIFF_INCLUDE_UNMODIFIED);
      HHVM_RC_INT_SAME(GIT_DIFF_INCLUDE_TYPECHANGE);
      HHVM_RC_INT_SAME(GIT_DIFF_INCLUDE_TYPECHANGE_TREES);
      HHVM_RC_INT_SAME(GIT_DIFF_IGNORE_FILEMODE);
      HHVM_RC_INT_SAME(GIT_DIFF_IGNORE_SUBMODULES);
      HHVM_RC_INT_SAME(GIT_DIFF_IGNORE_CASE);
      HHVM_RC_INT_SAME(GIT_DIFF_DISABLE_PATHSPEC_MATCH);
      HHVM_RC_INT_SAME(GIT_DIFF_SKIP_BINARY_CHECK);
      HHVM_RC_INT_SAME(GIT_DIFF_ENABLE_FAST_UNTRACKED_DIRS);
      HHVM_RC_INT_SAME(GIT_DIFF_FORCE_TEXT);
      HHVM_RC_INT_SAME(GIT_DIFF_FORCE_BINARY);
      HHVM_RC_INT_SAME(GIT_DIFF_IGNORE_WHITESPACE);
      HHVM_RC_INT_SAME(GIT_DIFF_IGNORE_WHITESPACE_CHANGE);
      HHVM_RC_INT_SAME(GIT_DIFF_IGNORE_WHITESPACE_EOL);
      HHVM_RC_INT_SAME(GIT_DIFF_SHOW_UNTRACKED_CONTENT);
      HHVM_RC_INT_SAME(GIT_DIFF_SHOW_UNMODIFIED);
      HHVM_RC_INT_SAME(GIT_DIFF_PATIENCE);
      HHVM_RC_INT_SAME(GIT_DIFF_MINIMAL);

      // --------------- git_diff_flag_t ---------------
      HHVM_RC_INT_SAME(GIT_DIFF_FLAG_BINARY);
      HHVM_RC_INT_SAME(GIT_DIFF_FLAG_NOT_BINARY);
      HHVM_RC_INT_SAME(GIT_DIFF_FLAG_VALID_OID);

      // --------------- git_delta_t ---------------
      HHVM_RC_INT_SAME(GIT_DELTA_UNMODIFIED);
      HHVM_RC_INT_SAME(GIT_DELTA_ADDED);
      HHVM_RC_INT_SAME(GIT_DELTA_DELETED);
      HHVM_RC_INT_SAME(GIT_DELTA_MODIFIED);
      HHVM_RC_INT_SAME(GIT_DELTA_RENAMED);
      HHVM_RC_INT_SAME(GIT_DELTA_COPIED);
      HHVM_RC_INT_SAME(GIT_DELTA_IGNORED);
      HHVM_RC_INT_SAME(GIT_DELTA_UNTRACKED);
      HHVM_RC_INT_SAME(GIT_DELTA_TYPECHANGE);

      // --------------- git_diff_line_t ---------------
      HHVM_RC_INT_SAME(GIT_DIFF_LINE_CONTEXT);
      HHVM_RC_INT_SAME(GIT_DIFF_LINE_ADDITION);
      HHVM_RC_INT_SAME(GIT_DIFF_LINE_DELETION);
      HHVM_RC_INT_SAME(GIT_DIFF_LINE_CONTEXT_EOFNL);
      HHVM_RC_INT_SAME(GIT_DIFF_LINE_ADD_EOFNL);
      HHVM_RC_INT_SAME(GIT_DIFF_LINE_DEL_EOFNL);
      HHVM_RC_INT_SAME(GIT_DIFF_LINE_FILE_HDR);
      HHVM_RC_INT_SAME(GIT_DIFF_LINE_HUNK_HDR);
      HHVM_RC_INT_SAME(GIT_DIFF_LINE_BINARY);

      // --------------- git_diff_find_t ---------------
      HHVM_RC_INT_SAME(GIT_DIFF_FIND_RENAMES);
      HHVM_RC_INT_SAME(GIT_DIFF_FIND_RENAMES_FROM_REWRITES);
      HHVM_RC_INT_SAME(GIT_DIFF_FIND_COPIES);
      HHVM_RC_INT_SAME(GIT_DIFF_FIND_COPIES_FROM_UNMODIFIED);
      HHVM_RC_INT_SAME(GIT_DIFF_FIND_REWRITES);
      HHVM_RC_INT_SAME(GIT_DIFF_BREAK_REWRITES);
      HHVM_RC_INT_SAME(GIT_DIFF_FIND_AND_BREAK_REWRITES);
      HHVM_RC_INT_SAME(GIT_DIFF_FIND_FOR_UNTRACKED);
      HHVM_RC_INT_SAME(GIT_DIFF_FIND_ALL);
      HHVM_RC_INT_SAME(GIT_DIFF_FIND_IGNORE_LEADING_WHITESPACE);
      HHVM_RC_INT_SAME(GIT_DIFF_FIND_IGNORE_WHITESPACE);
      HHVM_RC_INT_SAME(GIT_DIFF_FIND_DONT_IGNORE_WHITESPACE);
      HHVM_RC_INT_SAME(GIT_DIFF_FIND_EXACT_MATCH_ONLY);
      HHVM_RC_INT_SAME(GIT_DIFF_BREAK_REWRITES_FOR_RENAMES_ONLY);

      // --------------- git_diff_format_t ---------------
      HHVM_RC_INT_SAME(GIT_DIFF_FORMAT_PATCH);
      HHVM_RC_INT_SAME(GIT_DIFF_FORMAT_PATCH_HEADER);
      HHVM_RC_INT_SAME(GIT_DIFF_FORMAT_RAW);
      HHVM_RC_INT_SAME(GIT_DIFF_FORMAT_NAME_ONLY);
      HHVM_RC_INT_SAME(GIT_DIFF_FORMAT_NAME_STATUS);


      // --------------- errors.h ---------------

      // --------------- git_error_code ---------------
      HHVM_RC_INT_SAME(GIT_OK);
      HHVM_RC_INT_SAME(GIT_ERROR);
      HHVM_RC_INT_SAME(GIT_ENOTFOUND);
      HHVM_RC_INT_SAME(GIT_EEXISTS);
      HHVM_RC_INT_SAME(GIT_EAMBIGUOUS);
      HHVM_RC_INT_SAME(GIT_EBUFS);
      HHVM_RC_INT_SAME(GIT_EUSER);
      HHVM_RC_INT_SAME(GIT_EBAREREPO);
      HHVM_RC_INT_SAME(GIT_EUNBORNBRANCH);
      HHVM_RC_INT_SAME(GIT_EUNMERGED);
      HHVM_RC_INT_SAME(GIT_ENONFASTFORWARD);
      HHVM_RC_INT_SAME(GIT_EINVALIDSPEC);
      HHVM_RC_INT_SAME(GIT_EMERGECONFLICT);
      HHVM_RC_INT_SAME(GIT_ELOCKED);
      HHVM_RC_INT_SAME(GIT_PASSTHROUGH);
      HHVM_RC_INT_SAME(GIT_ITEROVER);

      // --------------- git_error_t ---------------
      HHVM_RC_INT_SAME(GITERR_NONE);
      HHVM_RC_INT_SAME(GITERR_NOMEMORY);
      HHVM_RC_INT_SAME(GITERR_OS);
      HHVM_RC_INT_SAME(GITERR_INVALID);
      HHVM_RC_INT_SAME(GITERR_REFERENCE);
      HHVM_RC_INT_SAME(GITERR_ZLIB);
      HHVM_RC_INT_SAME(GITERR_REPOSITORY);
      HHVM_RC_INT_SAME(GITERR_CONFIG);
      HHVM_RC_INT_SAME(GITERR_REGEX);
      HHVM_RC_INT_SAME(GITERR_ODB);
      HHVM_RC_INT_SAME(GITERR_INDEX);
      HHVM_RC_INT_SAME(GITERR_OBJECT);
      HHVM_RC_INT_SAME(GITERR_NET);
      HHVM_RC_INT_SAME(GITERR_TAG);
      HHVM_RC_INT_SAME(GITERR_TREE);
      HHVM_RC_INT_SAME(GITERR_INDEXER);
      HHVM_RC_INT_SAME(GITERR_SSL);
      HHVM_RC_INT_SAME(GITERR_SUBMODULE);
      HHVM_RC_INT_SAME(GITERR_THREAD);
      HHVM_RC_INT_SAME(GITERR_STASH);
      HHVM_RC_INT_SAME(GITERR_CHECKOUT);
      HHVM_RC_INT_SAME(GITERR_FETCHHEAD);
      HHVM_RC_INT_SAME(GITERR_MERGE);
      HHVM_RC_INT_SAME(GITERR_SSH);
      HHVM_RC_INT_SAME(GITERR_FILTER);


      // --------------- filter.h ---------------

      // --------------- git_filter_mode_t ---------------
      HHVM_RC_INT_SAME(GIT_FILTER_TO_WORKTREE);
      HHVM_RC_INT_SAME(GIT_FILTER_SMUDGE);
      HHVM_RC_INT_SAME(GIT_FILTER_TO_ODB);
      HHVM_RC_INT_SAME(GIT_FILTER_CLEAN);


      // --------------- index.h ---------------

      // --------------- git_indexcap_t ---------------
      HHVM_RC_INT_SAME(GIT_INDEXCAP_IGNORE_CASE);
      HHVM_RC_INT_SAME(GIT_INDEXCAP_NO_FILEMODE);
      HHVM_RC_INT_SAME(GIT_INDEXCAP_NO_SYMLINKS);
      HHVM_RC_INT_SAME(GIT_INDEXCAP_FROM_OWNER);

      // --------------- git_index_add_option_t ---------------
      HHVM_RC_INT_SAME(GIT_INDEX_ADD_DEFAULT);
      HHVM_RC_INT_SAME(GIT_INDEX_ADD_FORCE);
      HHVM_RC_INT_SAME(GIT_INDEX_ADD_DISABLE_PATHSPEC_MATCH);
      HHVM_RC_INT_SAME(GIT_INDEX_ADD_CHECK_PATHSPEC);


      // --------------- merge.h ---------------

      // --------------- git_merge_tree_flag_t ---------------
      HHVM_RC_INT_SAME(GIT_MERGE_TREE_FIND_RENAMES);

      // --------------- git_merge_automerge_flags ---------------
      HHVM_RC_INT_SAME(GIT_MERGE_AUTOMERGE_NORMAL);
      HHVM_RC_INT_SAME(GIT_MERGE_AUTOMERGE_NONE);
      HHVM_RC_INT_SAME(GIT_MERGE_AUTOMERGE_FAVOR_OURS);
      HHVM_RC_INT_SAME(GIT_MERGE_AUTOMERGE_FAVOR_THEIRS);

      // --------------- git_merge_flags_t ---------------
      HHVM_RC_INT_SAME(GIT_MERGE_NO_FASTFORWARD);
      HHVM_RC_INT_SAME(GIT_MERGE_FASTFORWARD_ONLY);


      // --------------- net.h ---------------

      // --------------- git_direction ---------------
      HHVM_RC_INT_SAME(GIT_DIRECTION_FETCH);
      HHVM_RC_INT_SAME(GIT_DIRECTION_PUSH);


      // --------------- odb_backend.h ---------------

      // --------------- git_odb_stream_t ---------------
      HHVM_RC_INT_SAME(GIT_STREAM_RDONLY);
      HHVM_RC_INT_SAME(GIT_STREAM_WRONLY);
      HHVM_RC_INT_SAME(GIT_STREAM_RW);


      // --------------- pack.h ---------------

      // --------------- git_packbuilder_stage_t ---------------
      HHVM_RC_INT_SAME(GIT_PACKBUILDER_ADDING_OBJECTS);
      HHVM_RC_INT_SAME(GIT_PACKBUILDER_DELTAFICATION);


      // --------------- pathspec.h ---------------

      // --------------- git_pathspec_flag_t ---------------
      HHVM_RC_INT_SAME(GIT_PATHSPEC_DEFAULT);
      HHVM_RC_INT_SAME(GIT_PATHSPEC_IGNORE_CASE);
      HHVM_RC_INT_SAME(GIT_PATHSPEC_USE_CASE);
      HHVM_RC_INT_SAME(GIT_PATHSPEC_NO_GLOB);
      HHVM_RC_INT_SAME(GIT_PATHSPEC_NO_MATCH_ERROR);
      HHVM_RC_INT_SAME(GIT_PATHSPEC_FIND_FAILURES);
      HHVM_RC_INT_SAME(GIT_PATHSPEC_FAILURES_ONLY);


      // --------------- refs.h ---------------

      // --------------- git_reference_normalize_t ---------------
      HHVM_RC_INT_SAME(GIT_REF_FORMAT_NORMAL);
      HHVM_RC_INT_SAME(GIT_REF_FORMAT_ALLOW_ONELEVEL);
      HHVM_RC_INT_SAME(GIT_REF_FORMAT_REFSPEC_PATTERN);
      HHVM_RC_INT_SAME(GIT_REF_FORMAT_REFSPEC_SHORTHAND);


      // --------------- remote.h ---------------

      // --------------- git_remote_completion_type ---------------
      HHVM_RC_INT_SAME(GIT_REMOTE_COMPLETION_DOWNLOAD);
      HHVM_RC_INT_SAME(GIT_REMOTE_COMPLETION_INDEXING);
      HHVM_RC_INT_SAME(GIT_REMOTE_COMPLETION_ERROR);

      // --------------- git_remote_autotag_option_t ---------------
      HHVM_RC_INT_SAME(GIT_REMOTE_DOWNLOAD_TAGS_AUTO);
      HHVM_RC_INT_SAME(GIT_REMOTE_DOWNLOAD_TAGS_NONE);
      HHVM_RC_INT_SAME(GIT_REMOTE_DOWNLOAD_TAGS_ALL);


      // --------------- repository.h ---------------

      // --------------- git_repository_open_flag_t ---------------
      HHVM_RC_INT_SAME(GIT_REPOSITORY_OPEN_NO_SEARCH);
      HHVM_RC_INT_SAME(GIT_REPOSITORY_OPEN_CROSS_FS);
      HHVM_RC_INT_SAME(GIT_REPOSITORY_OPEN_BARE);

      // --------------- git_repository_init_flag_t ---------------
      HHVM_RC_INT_SAME(GIT_REPOSITORY_INIT_BARE);
      HHVM_RC_INT_SAME(GIT_REPOSITORY_INIT_NO_REINIT);
      HHVM_RC_INT_SAME(GIT_REPOSITORY_INIT_NO_DOTGIT_DIR);
      HHVM_RC_INT_SAME(GIT_REPOSITORY_INIT_MKDIR);
      HHVM_RC_INT_SAME(GIT_REPOSITORY_INIT_MKPATH);
      HHVM_RC_INT_SAME(GIT_REPOSITORY_INIT_EXTERNAL_TEMPLATE);

      // --------------- git_repository_init_mode_t ---------------
      HHVM_RC_INT_SAME(GIT_REPOSITORY_INIT_SHARED_UMASK);
      HHVM_RC_INT_SAME(GIT_REPOSITORY_INIT_SHARED_GROUP);
      HHVM_RC_INT_SAME(GIT_REPOSITORY_INIT_SHARED_ALL);

      // --------------- git_repository_state_t ---------------
      HHVM_RC_INT_SAME(GIT_REPOSITORY_STATE_NONE);
      HHVM_RC_INT_SAME(GIT_REPOSITORY_STATE_MERGE);
      HHVM_RC_INT_SAME(GIT_REPOSITORY_STATE_REVERT);
      HHVM_RC_INT_SAME(GIT_REPOSITORY_STATE_CHERRY_PICK);
      HHVM_RC_INT_SAME(GIT_REPOSITORY_STATE_BISECT);
      HHVM_RC_INT_SAME(GIT_REPOSITORY_STATE_REBASE);
      HHVM_RC_INT_SAME(GIT_REPOSITORY_STATE_REBASE_INTERACTIVE);
      HHVM_RC_INT_SAME(GIT_REPOSITORY_STATE_REBASE_MERGE);
      HHVM_RC_INT_SAME(GIT_REPOSITORY_STATE_APPLY_MAILBOX);
      HHVM_RC_INT_SAME(GIT_REPOSITORY_STATE_APPLY_MAILBOX_OR_REBASE);


      // --------------- reset.h ---------------

      // --------------- git_reset_t ---------------
      HHVM_RC_INT_SAME(GIT_RESET_SOFT);
      HHVM_RC_INT_SAME(GIT_RESET_MIXED);
      HHVM_RC_INT_SAME(GIT_RESET_HARD);


      // --------------- revparse.h ---------------

      // --------------- git_revparse_mode_t ---------------
      HHVM_RC_INT_SAME(GIT_REVPARSE_SINGLE);
      HHVM_RC_INT_SAME(GIT_REVPARSE_RANGE);
      HHVM_RC_INT_SAME(GIT_REVPARSE_MERGE_BASE);


      // --------------- stash.h ---------------

      // --------------- git_stash_flags ---------------
      HHVM_RC_INT_SAME(GIT_STASH_DEFAULT);
      HHVM_RC_INT_SAME(GIT_STASH_KEEP_INDEX);
      HHVM_RC_INT_SAME(GIT_STASH_INCLUDE_UNTRACKED);
      HHVM_RC_INT_SAME(GIT_STASH_INCLUDE_IGNORED);


      // --------------- status.h ---------------

      // --------------- git_status_t ---------------
      HHVM_RC_INT_SAME(GIT_STATUS_CURRENT);
      HHVM_RC_INT_SAME(GIT_STATUS_INDEX_NEW);
      HHVM_RC_INT_SAME(GIT_STATUS_INDEX_MODIFIED);
      HHVM_RC_INT_SAME(GIT_STATUS_INDEX_DELETED);
      HHVM_RC_INT_SAME(GIT_STATUS_INDEX_RENAMED);
      HHVM_RC_INT_SAME(GIT_STATUS_INDEX_TYPECHANGE);
      HHVM_RC_INT_SAME(GIT_STATUS_WT_NEW);
      HHVM_RC_INT_SAME(GIT_STATUS_WT_MODIFIED);
      HHVM_RC_INT_SAME(GIT_STATUS_WT_DELETED);
      HHVM_RC_INT_SAME(GIT_STATUS_WT_TYPECHANGE);
      HHVM_RC_INT_SAME(GIT_STATUS_WT_RENAMED);
      HHVM_RC_INT_SAME(GIT_STATUS_IGNORED);

      // --------------- git_status_show_t ---------------
      HHVM_RC_INT_SAME(GIT_STATUS_SHOW_INDEX_AND_WORKDIR);
      HHVM_RC_INT_SAME(GIT_STATUS_SHOW_INDEX_ONLY);
      HHVM_RC_INT_SAME(GIT_STATUS_SHOW_WORKDIR_ONLY);

      // --------------- git_status_opt_t ---------------
      HHVM_RC_INT_SAME(GIT_STATUS_OPT_INCLUDE_UNTRACKED);
      HHVM_RC_INT_SAME(GIT_STATUS_OPT_INCLUDE_IGNORED);
      HHVM_RC_INT_SAME(GIT_STATUS_OPT_INCLUDE_UNMODIFIED);
      HHVM_RC_INT_SAME(GIT_STATUS_OPT_EXCLUDE_SUBMODULES);
      HHVM_RC_INT_SAME(GIT_STATUS_OPT_RECURSE_UNTRACKED_DIRS);
      HHVM_RC_INT_SAME(GIT_STATUS_OPT_DISABLE_PATHSPEC_MATCH);
      HHVM_RC_INT_SAME(GIT_STATUS_OPT_RECURSE_IGNORED_DIRS);
      HHVM_RC_INT_SAME(GIT_STATUS_OPT_RENAMES_HEAD_TO_INDEX);
      HHVM_RC_INT_SAME(GIT_STATUS_OPT_RENAMES_INDEX_TO_WORKDIR);
      HHVM_RC_INT_SAME(GIT_STATUS_OPT_SORT_CASE_SENSITIVELY);
      HHVM_RC_INT_SAME(GIT_STATUS_OPT_SORT_CASE_INSENSITIVELY);
      HHVM_RC_INT_SAME(GIT_STATUS_OPT_RENAMES_FROM_REWRITES);
      HHVM_RC_INT_SAME(GIT_STATUS_OPT_NO_REFRESH);


      // --------------- submodule.h ---------------

      // --------------- git_submodule_status_t ---------------
      HHVM_RC_INT_SAME(GIT_SUBMODULE_STATUS_IN_HEAD);
      HHVM_RC_INT_SAME(GIT_SUBMODULE_STATUS_IN_INDEX);
      HHVM_RC_INT_SAME(GIT_SUBMODULE_STATUS_IN_CONFIG);
      HHVM_RC_INT_SAME(GIT_SUBMODULE_STATUS_IN_WD);
      HHVM_RC_INT_SAME(GIT_SUBMODULE_STATUS_INDEX_ADDED);
      HHVM_RC_INT_SAME(GIT_SUBMODULE_STATUS_INDEX_DELETED);
      HHVM_RC_INT_SAME(GIT_SUBMODULE_STATUS_INDEX_MODIFIED);
      HHVM_RC_INT_SAME(GIT_SUBMODULE_STATUS_WD_UNINITIALIZED);
      HHVM_RC_INT_SAME(GIT_SUBMODULE_STATUS_WD_ADDED);
      HHVM_RC_INT_SAME(GIT_SUBMODULE_STATUS_WD_DELETED);
      HHVM_RC_INT_SAME(GIT_SUBMODULE_STATUS_WD_MODIFIED);
      HHVM_RC_INT_SAME(GIT_SUBMODULE_STATUS_WD_INDEX_MODIFIED);
      HHVM_RC_INT_SAME(GIT_SUBMODULE_STATUS_WD_WD_MODIFIED);
      HHVM_RC_INT_SAME(GIT_SUBMODULE_STATUS_WD_UNTRACKED);


      // --------------- trace.h ---------------

      // --------------- git_trace_level_t ---------------
      HHVM_RC_INT_SAME(GIT_TRACE_NONE);
      HHVM_RC_INT_SAME(GIT_TRACE_FATAL);
      HHVM_RC_INT_SAME(GIT_TRACE_ERROR);
      HHVM_RC_INT_SAME(GIT_TRACE_WARN);
      HHVM_RC_INT_SAME(GIT_TRACE_INFO);
      HHVM_RC_INT_SAME(GIT_TRACE_DEBUG);
      HHVM_RC_INT_SAME(GIT_TRACE_TRACE);


      // --------------- transport.h ---------------

      // --------------- git_credtype_t ---------------
      HHVM_RC_INT_SAME(GIT_CREDTYPE_USERPASS_PLAINTEXT);
      HHVM_RC_INT_SAME(GIT_CREDTYPE_SSH_KEY);
      HHVM_RC_INT_SAME(GIT_CREDTYPE_SSH_CUSTOM);
      HHVM_RC_INT_SAME(GIT_CREDTYPE_DEFAULT);

      // --------------- git_transport_flags_t ---------------
      HHVM_RC_INT_SAME(GIT_TRANSPORTFLAGS_NONE);
      HHVM_RC_INT_SAME(GIT_TRANSPORTFLAGS_NO_CHECK_CERT);

      // --------------- git_smart_service_t ---------------
      HHVM_RC_INT_SAME(GIT_SERVICE_UPLOADPACK_LS);
      HHVM_RC_INT_SAME(GIT_SERVICE_UPLOADPACK);
      HHVM_RC_INT_SAME(GIT_SERVICE_RECEIVEPACK_LS);
      HHVM_RC_INT_SAME(GIT_SERVICE_RECEIVEPACK);


      // --------------- tree.h ---------------

      // --------------- git_treewalk_mode ---------------
      HHVM_RC_INT_SAME(GIT_TREEWALK_PRE);
      HHVM_RC_INT_SAME(GIT_TREEWALK_POST);


      // --------------- types.h ---------------

      // --------------- git_otype ---------------
      HHVM_RC_INT_SAME(GIT_OBJ_ANY);
      HHVM_RC_INT_SAME(GIT_OBJ_BAD);
      HHVM_RC_INT_SAME(GIT_OBJ__EXT1);
      HHVM_RC_INT_SAME(GIT_OBJ_COMMIT);
      HHVM_RC_INT_SAME(GIT_OBJ_TREE);
      HHVM_RC_INT_SAME(GIT_OBJ_BLOB);
      HHVM_RC_INT_SAME(GIT_OBJ_TAG);
      HHVM_RC_INT_SAME(GIT_OBJ__EXT2);
      HHVM_RC_INT_SAME(GIT_OBJ_OFS_DELTA);
      HHVM_RC_INT_SAME(GIT_OBJ_REF_DELTA);

      // --------------- git_ref_t ---------------
      HHVM_RC_INT_SAME(GIT_REF_INVALID);
      HHVM_RC_INT_SAME(GIT_REF_OID);
      HHVM_RC_INT_SAME(GIT_REF_SYMBOLIC);
      HHVM_RC_INT_SAME(GIT_REF_LISTALL);

      // --------------- git_branch_t ---------------
      HHVM_RC_INT_SAME(GIT_BRANCH_LOCAL);
      HHVM_RC_INT_SAME(GIT_BRANCH_REMOTE);

      // --------------- git_filemode_t ---------------
      HHVM_RC_INT_SAME(GIT_FILEMODE_NEW);
      HHVM_RC_INT_SAME(GIT_FILEMODE_TREE);
      HHVM_RC_INT_SAME(GIT_FILEMODE_BLOB);
      HHVM_RC_INT_SAME(GIT_FILEMODE_BLOB_EXECUTABLE);
      HHVM_RC_INT_SAME(GIT_FILEMODE_LINK);
      HHVM_RC_INT_SAME(GIT_FILEMODE_COMMIT);

      // --------------- git_submodule_update_t ---------------
      HHVM_RC_INT_SAME(GIT_SUBMODULE_UPDATE_RESET);
      HHVM_RC_INT_SAME(GIT_SUBMODULE_UPDATE_CHECKOUT);
      HHVM_RC_INT_SAME(GIT_SUBMODULE_UPDATE_REBASE);
      HHVM_RC_INT_SAME(GIT_SUBMODULE_UPDATE_MERGE);
      HHVM_RC_INT_SAME(GIT_SUBMODULE_UPDATE_NONE);
      HHVM_RC_INT_SAME(GIT_SUBMODULE_UPDATE_DEFAULT);

      // --------------- git_submodule_ignore_t ---------------
      HHVM_RC_INT_SAME(GIT_SUBMODULE_IGNORE_RESET);
      HHVM_RC_INT_SAME(GIT_SUBMODULE_IGNORE_NONE);
      HHVM_RC_INT_SAME(GIT_SUBMODULE_IGNORE_UNTRACKED);
      HHVM_RC_INT_SAME(GIT_SUBMODULE_IGNORE_DIRTY);
      HHVM_RC_INT_SAME(GIT_SUBMODULE_IGNORE_ALL);
      HHVM_RC_INT_SAME(GIT_SUBMODULE_IGNORE_DEFAULT);


      loadSystemlib();
  }
} s_git2_extension;

HHVM_GET_MODULE(git2)
} // namespace HPHP
