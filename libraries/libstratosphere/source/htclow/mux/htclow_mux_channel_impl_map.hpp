/*
 * Copyright (c) 2019-2020 Adubbz, Atmosphère-NX
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
#pragma once
#include <stratosphere.hpp>
#include "htclow_mux_task_manager.hpp"

namespace ams::htclow {

    class PacketFactory;

    namespace ctrl {

        class HtcctrlStateMachine;

    }

}

namespace ams::htclow::mux {

    class ChannelImplMap {
        NON_COPYABLE(ChannelImplMap);
        NON_MOVEABLE(ChannelImplMap);
        public:
            static constexpr int MaxChannelCount = 64;

            using MapType = util::FixedMap<impl::ChannelInternalType, int>;

            static constexpr size_t MapRequiredMemorySize = MapType::GetRequiredMemorySize(MaxChannelCount);
        private:
            PacketFactory *m_packet_factory;
            ctrl::HtcctrlStateMachine *m_state_machine;
            TaskManager *m_task_manager;
            os::EventType *m_event;
            u8 m_map_buffer[MapRequiredMemorySize];
            MapType m_map;
            u8 m_storage[0x5200]; /* TODO */
            bool m_storage_valid[MaxChannelCount];
        public:
            ChannelImplMap(PacketFactory *pf, ctrl::HtcctrlStateMachine *sm, TaskManager *tm, os::EventType *ev);
    };

}
