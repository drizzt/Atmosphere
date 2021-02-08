/*
 * Copyright (c) 2018-2020 Atmosphère-NX
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <stratosphere.hpp>
#include "htclow_mux_channel_impl.hpp"

namespace ams::htclow::mux {

    void ChannelImpl::SetVersion(s16 version) {
        /* Sanity check the version. */
        AMS_ASSERT(version <= ProtocolVersion);

        /* Set version. */
        m_version = version;
        m_send_buffer.SetVersion(version);
    }

}