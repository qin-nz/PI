/* Copyright 2013-present Barefoot Networks, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Antonin Bas (antonin@barefootnetworks.com)
 *
 */

//! @file

#ifndef PI_INC_PI_PI_ACT_PROF_H_
#define PI_INC_PI_PI_ACT_PROF_H_

#include <PI/pi_tables.h>

#ifdef __cplusplus
extern "C" {
#endif

//! Create an indirect member in an action profile.
pi_status_t pi_act_prof_mbr_create(pi_session_handle_t session_handle,
                                   pi_dev_tgt_t dev_tgt, pi_p4_id_t act_prof_id,
                                   const pi_action_data_t *action_data,
                                   pi_indirect_handle_t *mbr_handle);

//! Delete an indirect member.
pi_status_t pi_act_prof_mbr_delete(pi_session_handle_t session_handle,
                                   pi_dev_id_t dev_id, pi_p4_id_t act_prof_id,
                                   pi_indirect_handle_t mbr_handle);

//! Modify an indirect member.
pi_status_t pi_act_prof_mbr_modify(pi_session_handle_t session_handle,
                                   pi_dev_id_t dev_id, pi_p4_id_t act_prof_id,
                                   pi_indirect_handle_t mbr_handle,
                                   const pi_action_data_t *action_data);

//! Create an indirect group in an action profile. A group is a set of members.
pi_status_t pi_act_prof_grp_create(pi_session_handle_t session_handle,
                                   pi_dev_tgt_t dev_tgt, pi_p4_id_t act_prof_id,
                                   size_t max_size,
                                   pi_indirect_handle_t *grp_handle);

//! Deletes an indirect group.
pi_status_t pi_act_prof_grp_delete(pi_session_handle_t session_handle,
                                   pi_dev_id_t dev_id, pi_p4_id_t act_prof_id,
                                   pi_indirect_handle_t grp_handle);

//! Adds a member to a group.
pi_status_t pi_act_prof_grp_add_mbr(pi_session_handle_t session_handle,
                                    pi_dev_id_t dev_id, pi_p4_id_t act_prof_id,
                                    pi_indirect_handle_t grp_handle,
                                    pi_indirect_handle_t mbr_handle);

//! Remove a member from a group.
pi_status_t pi_act_prof_grp_remove_mbr(pi_session_handle_t session_handle,
                                       pi_dev_id_t dev_id,
                                       pi_p4_id_t act_prof_id,
                                       pi_indirect_handle_t grp_handle,
                                       pi_indirect_handle_t mbr_handle);

typedef struct pi_act_prof_fetch_res_s pi_act_prof_fetch_res_t;

//! Retrieve all entries in an action profile as one big blob
pi_status_t pi_act_prof_entries_fetch(pi_session_handle_t session_handle,
                                      pi_dev_id_t dev_id,
                                      pi_p4_id_t act_prof_id,
                                      pi_act_prof_fetch_res_t **res);

//! Need to be called after a pi_act_prof_entries_fetch, once you wish the
//! memory to be released.
pi_status_t pi_act_prof_entries_fetch_done(pi_session_handle_t session_handle,
                                           pi_act_prof_fetch_res_t *res);

//! Returns the number of members obtained with pi_act_prof_entries_fetch.
size_t pi_act_prof_mbrs_num(pi_act_prof_fetch_res_t *res);

//! Returns the number of groups obtained with pi_act_prof_entries_fetch.
size_t pi_act_prof_grps_num(pi_act_prof_fetch_res_t *res);

//! Iterates through members retrieved with pi_act_prof_entries_fetch.
size_t pi_act_prof_mbrs_next(pi_act_prof_fetch_res_t *res,
                             pi_action_data_t **action_data,
                             pi_indirect_handle_t *mbr_handle);

//! Iterates through groups retrieved with pi_act_prof_entries_fetch.
size_t pi_act_prof_grps_next(pi_act_prof_fetch_res_t *res,
                             pi_indirect_handle_t **mbrs, size_t *num_mbrs,
                             pi_indirect_handle_t *grp_handle);

#ifdef __cplusplus
}
#endif

#endif  // PI_INC_PI_PI_ACT_PROF_H_
