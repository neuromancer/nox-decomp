function initfs() {
    FS.mkdir('/assets');
    FS.mount(IDBFS, {}, '/assets');

    let preload = [
        "/assets/audio.bag",
        "/assets/audio.idx",
        "/assets/default.cfg",
        "/assets/default.fnt",
        "/assets/gamedata.bin",
        "/assets/large.fnt",
        "/assets/mapcycle.txt",
        "/assets/monster.bin",
        "/assets/Modifier.bin",
        "/assets/nox.csf",
        "/assets/number.fnt",
        "/assets/OTQuest.rul",
        "/assets/small.fnt",
        "/assets/Save",
        "/assets/SoundSet.bin",
        "/assets/thing.bin",
        "/assets/video.bag.0",
        "/assets/video.bag.1",
        "/assets/video.bag.2",
        "/assets/video.bag.3",
        "/assets/video.bag.4",
        "/assets/video.bag.5",
        "/assets/video.bag.6",
        "/assets/video.bag.7",
        "/assets/video.idx",
        "/assets/window",
        "/assets/window/access.wnd",
        "/assets/window/advanced.wnd",
        "/assets/window/advidop2.wnd",
        "/assets/window/advidopt.wnd",
        "/assets/window/advserv.wnd",
        "/assets/window/ArnaMain.wnd",
        "/assets/window/audtest.wnd",
        "/assets/window/Briefing.wnd",
        "/assets/window/chared2.wnd",
        "/assets/window/charedit.wnd",
        "/assets/window/conninfo.wnd",
        "/assets/window/conntype.wnd",
        "/assets/window/Dialog.wnd",
        "/assets/window/discon.wnd",
        "/assets/window/dlg.wnd",
        "/assets/window/filters.wnd",
        "/assets/window/filter.wnd",
        "/assets/window/gamesel.wnd",
        "/assets/window/gameset.wnd",
        "/assets/window/general.wnd",
        "/assets/window/GGOver.wnd",
        "/assets/window/GuiChat.wnd",
        "/assets/window/GUI_CTF.wnd",
        "/assets/window/gui_fb.wnd",
        "/assets/window/GuiFps.wnd",
        "/assets/window/GuiKick.wnd",
        "/assets/window/identify.wnd",
        "/assets/window/InputCfg.wnd",
        "/assets/window/journal.wnd",
        "/assets/window/laccess.wnd",
        "/assets/window/ladvserv.wnd",
        "/assets/window/ldlg.wnd",
        "/assets/window/legal.wnd",
        "/assets/window/lgeneral.wnd",
        "/assets/window/load.wnd",
        "/assets/window/locale.wnd",
        "/assets/window/lplayers.wnd",
        "/assets/window/lsanchlp.wnd",
        "/assets/window/lservopt.wnd",
        "/assets/window/lwadvsrv.wnd",
        "/assets/window/lwgenerl.wnd",
        "/assets/window/MainBG.wnd",
        "/assets/window/MainMenu.wnd",
        "/assets/window/mapdnld.wnd",
        "/assets/window/modify.wnd",
        "/assets/window/motd.wnd",
        "/assets/window/multiopt.wnd",
        "/assets/window/MultMove.wnd",
        "/assets/window/noxgamex.wnd",
        "/assets/window/noxworld.wnd",
        "/assets/window/objlst.wnd",
        "/assets/window/Options.wnd",
        "/assets/window/OptsBack.wnd",
        "/assets/window/players.wnd",
        "/assets/window/playrlst.wnd",
        "/assets/window/proxlist.wnd",
        "/assets/window/QuitMenu.wnd",
        "/assets/window/recplay.wnd",
        "/assets/window/rulelist.wnd",
        "/assets/window/rules.wnd",
        "/assets/window/sanchlp.wnd",
        "/assets/window/save.wnd",
        "/assets/window/SelChar.wnd",
        "/assets/window/SelClass.wnd",
        "/assets/window/SelColor.wnd",
        "/assets/window/SERVLIST.WND",
        "/assets/window/servopts.wnd",
        "/assets/window/Shop.wnd",
        "/assets/window/SKey.wnd",
        "/assets/window/spelllst.wnd",
        "/assets/window/Trade.wnd",
        "/assets/window/videoopt.wnd",
        "/assets/window/wAccess.wnd",
        "/assets/window/wAdvServ.wnd",
        "/assets/window/wGeneral.wnd",
        "/assets/window/wolapi.wnd",
        "/assets/window/wolchan.wnd",
        "/assets/window/wolchat.wnd",
        "/assets/window/woldisc.wnd",
        "/assets/window/wolfind.wnd",
        "/assets/window/wolopt.wnd",
        "/assets/window/wolprog.wnd",
        "/assets/window/wolreg.wnd",
        "/assets/window/wServopt.wnd",
        "/assets/window/yesno.wnd",
        "/assets/maps",
        "/assets/maps/con01a",
        "/assets/maps/con01a/con01a.map",
        "/assets/maps/con02a",
        "/assets/maps/con02a/con02a.map",
        "/assets/maps/con03a",
        "/assets/maps/con03a/con03a.map",
        "/assets/maps/con03b",
        "/assets/maps/con03b/con03b.map",
        "/assets/maps/con04a",
        "/assets/maps/con04a/con04a.map",
        "/assets/maps/con04b",
        "/assets/maps/con04b/con04b.map",
        "/assets/maps/con04c",
        "/assets/maps/con04c/con04c.map",
        "/assets/maps/con05a",
        "/assets/maps/con05a/con05a.map",
        "/assets/maps/con05b",
        "/assets/maps/con05b/con05b.map",
        "/assets/maps/con05c",
        "/assets/maps/con05c/con05c.map",
        "/assets/maps/con06a",
        "/assets/maps/con06a/con06a.map",
        "/assets/maps/con06b",
        "/assets/maps/con06b/con06b.map",
        "/assets/maps/con07a",
        "/assets/maps/con07a/con07a.map",
        "/assets/maps/con07b",
        "/assets/maps/con07b/con07b.map",
        "/assets/maps/con07c",
        "/assets/maps/con07c/con07c.map",
        "/assets/maps/con07d",
        "/assets/maps/con07d/con07d.map",
        "/assets/maps/con07e",
        "/assets/maps/con07e/con07e.map",
        "/assets/maps/con07f",
        "/assets/maps/con07f/con07f.map",
        "/assets/maps/con07g",
        "/assets/maps/con07g/con07g.map",
        "/assets/maps/con07h",
        "/assets/maps/con07h/con07h.map",
        "/assets/maps/con08a",
        "/assets/maps/con08a/con08a.map",
        "/assets/maps/con08b",
        "/assets/maps/con08b/con08b.map",
        "/assets/maps/con08c",
        "/assets/maps/con08c/con08c.map",
        "/assets/maps/con08d",
        "/assets/maps/con08d/con08d.map",
        "/assets/maps/con08e",
        "/assets/maps/con08e/con08e.map",
        "/assets/maps/con09a",
        "/assets/maps/con09a/con09a.map",
        "/assets/maps/con09b",
        "/assets/maps/con09b/con09b.map",
        "/assets/maps/con09c",
        "/assets/maps/con09c/con09c.map",
        "/assets/maps/con09d",
        "/assets/maps/con09d/con09d.map",
        "/assets/maps/con10a",
        "/assets/maps/con10a/con10a.map",
        "/assets/maps/con10b",
        "/assets/maps/con10b/con10b.map",
        "/assets/maps/con10c",
        "/assets/maps/con10c/con10c.map",
        "/assets/maps/con10d",
        "/assets/maps/con10d/con10d.map",
        "/assets/maps/con11a",
        "/assets/maps/con11a/con11a.map",
        "/assets/maps/Estate",
        "/assets/maps/Estate/Estate.map",
        "/assets/maps/Estate/Estate.nxz",
        "/assets/maps/Estate/Estate.rul",
        "/assets/maps/G_CastlD",
        "/assets/maps/G_CastlD/G_CastlD.map",
        "/assets/maps/G_CastlD/G_CastlD.nxz",
        "/assets/maps/G_Castle",
        "/assets/maps/G_Castle/G_Castle.map",
        "/assets/maps/G_Castle/G_Castle.nxz",
        "/assets/maps/G_CryptD",
        "/assets/maps/G_CryptD/G_CryptD.map",
        "/assets/maps/G_CryptD/G_CryptD.nxz",
        "/assets/maps/G_Crypts",
        "/assets/maps/G_Crypts/G_Crypts.map",
        "/assets/maps/G_Crypts/G_Crypts.nxz",
        "/assets/maps/G_ForesD",
        "/assets/maps/G_ForesD/G_ForesD.map",
        "/assets/maps/G_ForesD/G_ForesD.nxz",
        "/assets/maps/G_Forest",
        "/assets/maps/G_Forest/G_Forest.map",
        "/assets/maps/G_Forest/G_Forest.nxz",
        "/assets/maps/G_Lava",
        "/assets/maps/G_Lava/G_Lava.map",
        "/assets/maps/G_Lava/G_Lava.nxz",
        "/assets/maps/G_LOTD",
        "/assets/maps/G_LOTD/G_LOTD.map",
        "/assets/maps/G_LOTD/G_LOTD.nxz",
        "/assets/maps/G_LOTDD",
        "/assets/maps/G_LOTDD/G_LOTDD.map",
        "/assets/maps/G_LOTDD/G_LOTDD.nxz",
        "/assets/maps/G_Mines",
        "/assets/maps/G_Mines/G_Mines.map",
        "/assets/maps/G_Mines/G_Mines.nxz",
        "/assets/maps/G_Swamp",
        "/assets/maps/G_Swamp/G_Swamp.map",
        "/assets/maps/G_Swamp/G_Swamp.nxz",
        "/assets/maps/G_TemplD",
        "/assets/maps/G_TemplD/G_TemplD.map",
        "/assets/maps/G_TemplD/G_TemplD.nxz",
        "/assets/maps/G_Temple",
        "/assets/maps/G_Temple/G_Temple.map",
        "/assets/maps/G_Temple/G_Temple.nxz",
        "/assets/maps/So_Beach",
        "/assets/maps/So_Beach/So_Beach.map",
        "/assets/maps/So_Beach/So_Beach.nxz",
        "/assets/maps/So_Brin",
        "/assets/maps/So_Brin/So_Brin.map",
        "/assets/maps/So_Brin/So_Brin.nxz",
        "/assets/maps/So_Druid",
        "/assets/maps/So_Druid/So_Druid.map",
        "/assets/maps/So_Druid/So_Druid.nxz",
        "/assets/maps/So_Dun",
        "/assets/maps/So_Dun/So_Dun.map",
        "/assets/maps/So_Dun/So_Dun.nxz",
        "/assets/maps/So_FOV",
        "/assets/maps/So_FOV/So_FOV.map",
        "/assets/maps/So_FOV/So_FOV.nxz",
        "/assets/maps/So_Galav",
        "/assets/maps/So_Galav/So_Galav.map",
        "/assets/maps/So_Galav/So_Galav.nxz",
        "/assets/maps/So_Grok",
        "/assets/maps/So_Grok/So_Grok.map",
        "/assets/maps/So_Grok/So_Grok.nxz",
        "/assets/maps/So_Ix",
        "/assets/maps/So_Ix/So_Ix.map",
        "/assets/maps/So_Ix/So_Ix.nxz",
        "/assets/maps/So_LOD",
        "/assets/maps/So_LOD/So_LOD.map",
        "/assets/maps/So_LOD/So_LOD.nxz",
        "/assets/maps/So_Mines",
        "/assets/maps/So_Mines/So_Mines.map",
        "/assets/maps/So_Mines/So_Mines.nxz",
        "/assets/maps/So_Mount",
        "/assets/maps/So_Mount/So_Mount.map",
        "/assets/maps/So_Mount/So_Mount.nxz",
        "/assets/maps/So_Open",
        "/assets/maps/So_Open/So_Open.map",
        "/assets/maps/So_Open/So_Open.nxz",
        "/assets/maps/So_Swamp",
        "/assets/maps/So_Swamp/So_Swamp.map",
        "/assets/maps/So_Swamp/So_Swamp.nxz",
        "/assets/maps/So_Waste",
        "/assets/maps/So_Waste/So_Waste.map",
        "/assets/maps/So_Waste/So_Waste.nxz",
        "/assets/maps/So_Woods",
        "/assets/maps/So_Woods/So_Woods.map",
        "/assets/maps/So_Woods/So_Woods.nxz",
        "/assets/maps/war01a",
        "/assets/maps/war01a/war01a.map",
        "/assets/maps/war02a",
        "/assets/maps/war02a/war02a.map",
        "/assets/maps/war02b",
        "/assets/maps/war02b/war02b.map",
        "/assets/maps/war03a",
        "/assets/maps/war03a/war03a.map",
        "/assets/maps/war03b",
        "/assets/maps/war03b/war03b.map",
        "/assets/maps/war03c",
        "/assets/maps/war03c/war03c.map",
        "/assets/maps/war03d",
        "/assets/maps/war03d/war03d.map",
        "/assets/maps/war04a",
        "/assets/maps/war04a/war04a.map",
        "/assets/maps/war04b",
        "/assets/maps/war04b/war04b.map",
        "/assets/maps/war04c",
        "/assets/maps/war04c/war04c.map",
        "/assets/maps/war05a",
        "/assets/maps/war05a/war05a.map",
        "/assets/maps/war05b",
        "/assets/maps/war05b/war05b.map",
        "/assets/maps/war05c",
        "/assets/maps/war05c/war05c.map",
        "/assets/maps/war06a",
        "/assets/maps/war06a/war06a.map",
        "/assets/maps/war06b",
        "/assets/maps/war06b/war06b.map",
        "/assets/maps/war07a",
        "/assets/maps/war07a/war07a.map",
        "/assets/maps/war07b",
        "/assets/maps/war07b/war07b.map",
        "/assets/maps/war07c",
        "/assets/maps/war07c/war07c.map",
        "/assets/maps/war07d",
        "/assets/maps/war07d/war07d.map",
        "/assets/maps/war07e",
        "/assets/maps/war07e/war07e.map",
        "/assets/maps/war07f",
        "/assets/maps/war07f/war07f.map",
        "/assets/maps/war07g",
        "/assets/maps/war07g/war07g.map",
        "/assets/maps/war07h",
        "/assets/maps/war07h/war07h.map",
        "/assets/maps/war08a",
        "/assets/maps/war08a/war08a.map",
        "/assets/maps/war08b",
        "/assets/maps/war08b/war08b.map",
        "/assets/maps/war08c",
        "/assets/maps/war08c/war08c.map",
        "/assets/maps/war08d",
        "/assets/maps/war08d/war08d.map",
        "/assets/maps/war08e",
        "/assets/maps/war08e/war08e.map",
        "/assets/maps/war09a",
        "/assets/maps/war09a/war09a.map",
        "/assets/maps/war09b",
        "/assets/maps/war09b/war09b.map",
        "/assets/maps/war09c",
        "/assets/maps/war09c/war09c.map",
        "/assets/maps/war09d",
        "/assets/maps/war09d/war09d.map",
        "/assets/maps/war10a",
        "/assets/maps/war10a/war10a.map",
        "/assets/maps/war10b",
        "/assets/maps/war10b/war10b.map",
        "/assets/maps/war10c",
        "/assets/maps/war10c/war10c.map",
        "/assets/maps/war10d",
        "/assets/maps/war10d/war10d.map",
        "/assets/maps/war11a",
        "/assets/maps/war11a/war11a.map",
        "/assets/maps/wiz01a",
        "/assets/maps/wiz01a/wiz01a.map",
        "/assets/maps/wiz02a",
        "/assets/maps/wiz02a/wiz02a.map",
        "/assets/maps/wiz02b",
        "/assets/maps/wiz02b/wiz02b.map",
        "/assets/maps/wiz02c",
        "/assets/maps/wiz02c/wiz02c.map",
        "/assets/maps/wiz03a",
        "/assets/maps/wiz03a/wiz03a.map",
        "/assets/maps/wiz03b",
        "/assets/maps/wiz03b/wiz03b.map",
        "/assets/maps/wiz03c",
        "/assets/maps/wiz03c/wiz03c.map",
        "/assets/maps/wiz04a",
        "/assets/maps/wiz04a/wiz04a.map",
        "/assets/maps/wiz04b",
        "/assets/maps/wiz04b/wiz04b.map",
        "/assets/maps/wiz04c",
        "/assets/maps/wiz04c/wiz04c.map",
        "/assets/maps/wiz05a",
        "/assets/maps/wiz05a/wiz05a.map",
        "/assets/maps/wiz05b",
        "/assets/maps/wiz05b/wiz05b.map",
        "/assets/maps/wiz05c",
        "/assets/maps/wiz05c/wiz05c.map",
        "/assets/maps/wiz06a",
        "/assets/maps/wiz06a/wiz06a.map",
        "/assets/maps/wiz06b",
        "/assets/maps/wiz06b/wiz06b.map",
        "/assets/maps/wiz06c",
        "/assets/maps/wiz06c/wiz06c.map",
        "/assets/maps/wiz07a",
        "/assets/maps/wiz07a/wiz07a.map",
        "/assets/maps/wiz07b",
        "/assets/maps/wiz07b/wiz07b.map",
        "/assets/maps/wiz07c",
        "/assets/maps/wiz07c/wiz07c.map",
        "/assets/maps/wiz07d",
        "/assets/maps/wiz07d/wiz07d.map",
        "/assets/maps/wiz07e",
        "/assets/maps/wiz07e/wiz07e.map",
        "/assets/maps/wiz07f",
        "/assets/maps/wiz07f/wiz07f.map",
        "/assets/maps/wiz08a",
        "/assets/maps/wiz08a/wiz08a.map",
        "/assets/maps/wiz08b",
        "/assets/maps/wiz08b/wiz08b.map",
        "/assets/maps/wiz08c",
        "/assets/maps/wiz08c/wiz08c.map",
        "/assets/maps/wiz08d",
        "/assets/maps/wiz08d/wiz08d.map",
        "/assets/maps/wiz08e",
        "/assets/maps/wiz08e/wiz08e.map",
        "/assets/maps/wiz09a",
        "/assets/maps/wiz09a/wiz09a.map",
        "/assets/maps/wiz09b",
        "/assets/maps/wiz09b/wiz09b.map",
        "/assets/maps/wiz09c",
        "/assets/maps/wiz09c/wiz09c.map",
        "/assets/maps/wiz09d",
        "/assets/maps/wiz09d/wiz09d.map",
        "/assets/maps/wiz10a",
        "/assets/maps/wiz10a/wiz10a.map",
        "/assets/maps/wiz10b",
        "/assets/maps/wiz10b/wiz10b.map",
        "/assets/maps/wiz10c",
        "/assets/maps/wiz10c/wiz10c.map",
        "/assets/maps/wiz10d",
        "/assets/maps/wiz10d/wiz10d.map",
        "/assets/maps/wiz11a",
        "/assets/maps/wiz11a/wiz11a.map",
    ];
    addRunDependency('syncfs');
    FS.syncfs(true, function (err) {
        preload.forEach(function (path) {
            try {
                if (FS.lookupPath(path).node)
                    return;
            } catch (err) {
            }
            if (!path.includes('.'))
                FS.mkdir(path, 0777);
            else
                FS.createPreloadedFile(path, null, path, true, true);
        });
        removeRunDependency('syncfs');
    });
}
Module.preRun = [initfs];

function atou8(data) {
    return new Uint8Array(atob(data).split('').map(function (c) { return c.charCodeAt(0) }))
}
function u8toa(data) {
    return btoa(String.fromCharCode.apply(null, data))
}
class Network {
    constructor(options) {
        this.options = options
        this.peers = {}
        this.recvQueue = {}
        this.state = null

        const onclose = () => {
            this.ws = null
            setTimeout(connect, 5000)
        }
        const onmessage = ({ data }) => {
            this.onmessage(JSON.parse(data))
        }
        const onopen = () => this.onopen()
        const connect = () => {
            const ws = this.ws = new WebSocket(options.url)
            ws.addEventListener('open', onopen)
            ws.addEventListener('close', onclose)
            ws.addEventListener('message', onmessage)
        }
        connect()
    }

    isready () {
        return this.ws !== null && this.ws.readyState == this.ws.OPEN
    }

    onopen () {
    }

    onmessage (data) {
        switch (data.type) {
            case 'ACCEPT': {
                const peer = this.peers[data.remote]
                peer.connection.setRemoteDescription(data.answer)
                break
            }
            case 'CONNECT': {
                const remote = data.remote
                const peerConnection = new RTCPeerConnection(this.options.webrtc)
                const peerChannel = peerConnection.createDataChannel('nox-game', {
                    negotiated: true,
                    id: 0
                })
                peerConnection.addEventListener('icecandidate', ({ candidate }) => {
                    if (candidate) {
                        this.ws.isready() && this.ws.send(JSON.stringify({
                            type: 'ICECANDIDATE',
                            remote,
                            candidate
                        }))
                    }
                })
                peerConnection.addEventListener('iceconnectionstatechange', function () {
                    console.log(peerConnection.iceConnectionState)
                })
                peerConnection.setRemoteDescription(data.offer)
                peerConnection.createAnswer().then((answer) => {
                    peerConnection.setLocalDescription(answer)
                    this.accept(remote, answer)
                    peerChannel.addEventListener('message', ({ data }) => this.onpacket(remote, data))
                })
                this.peers[remote] = {
                    id: remote,
                    connection: peerConnection,
                    channel: peerChannel
                }
                break
            }
            case 'ICECANDIDATE': {
                const peer = this.peers[data.remote]
                peer.connection.addIceCandidate(new RTCIceCandidate(data.candidate))
                break
            }
            case 'LIST': {
                for (let i = 0; i < data.servers.length; i++) {
                    this.recvQueue[data.port].push({
                        id: data.servers[i].id,
                        srcport: data.servers[i].port,
                        data: this.updateListSeq(data.seqnum, atou8(data.servers[i].data))
                    })
                }
                break
            }
        }
    }

    onpacket(id, data) {
        data = new Uint8Array(data);
        const srcport = (data[0] << 8) | data[1];
        const dstport = (data[2] << 8) | data[3];
        this.recvQueue[dstport].push({ id, srcport, data: data.subarray(4) })
    }

    updateListSeq (seqnum, data) {
        data[44] = seqnum >> 0
        data[45] = seqnum >> 8
        data[46] = seqnum >> 16
        data[47] = seqnum >> 24
        return data
    }

    listServers (seqnum, port) {
        this.ws.send(JSON.stringify({
            type: 'LIST',
            seqnum,
            port
        }))
    }

    registerServer (data) {
        this.ws.send(JSON.stringify({
            type: 'REGISTER',
            data: data ? u8toa(data) : null,
            port: this.lastDestPort
        }))
    }

    accept (remote, answer) {
        this.isready() && this.ws.send(JSON.stringify({
            type: 'ACCEPT',
            remote,
            answer
        }))
    }

    bind (destport) {
        // XXX HACK
        this.lastDestPort = destport

        this.recvQueue[destport] = []
    }

    connect (remote) {
        const peerConnection = new RTCPeerConnection(this.options.webrtc)
        const peerChannel = peerConnection.createDataChannel('nox-game', {
            negotiated: true,
            id: 0
        })
        peerChannel.addEventListener('message', ({ data }) => this.onpacket(remote, data))
        peerConnection.addEventListener('icecandidate', ({ candidate }) => {
            if (candidate) {
                this.isready() && this.ws.send(JSON.stringify({
                    type: 'ICECANDIDATE',
                    remote,
                    candidate
                }))
            }
        })
        peerChannel.addEventListener('open', () => {
            clearTimeout(timer)
            const peer = this.peers[remote]
            peer.channel = peerChannel
            for (let i = 0; i < peer.sendQueue.length; i++)
                peer.channel.send(peer.sendQueue[i])
            peer.sendQueue = null
        })
        peerConnection.createOffer().then((offer) => {
            peerConnection.setLocalDescription(offer)
            this.isready() && this.ws.send(JSON.stringify({
               type: 'CONNECT',
               remote,
               offer
            }))
        })
        this.peers[remote] = {
            id: remote,
            connection: peerConnection,
            channel: null,
            sendQueue: []
        }
        let timer = setTimeout(() => {
            console.log('Peer connection timed out.')
            delete this.peers[remote]
            peerChannel.close()
            peerConnection.close()
        }, 5000)
    }

    close () {
    }

    available (destport) {
        if (!this.recvQueue[destport].length)
            return 0
        return this.recvQueue[destport][0].data.length
    }

    recvfrom (destport) {
        if (!this.recvQueue[destport].length)
            return null, null
        const { id, srcport, data } = this.recvQueue[destport].shift()
        return [id, srcport, data]
    }

    sendto (srcport, id, destport, data) {
        data = Uint8Array.of(srcport >> 8, srcport, destport >> 8, destport, ...data)
        if (!this.peers[id])
            this.connect(id)

        const peer = this.peers[id]
        if (peer.channel)
            this.peers[id].channel.send(data)
        else
            peer.sendQueue.push(data)
    }
}

network = new Network({
    url: document.location.protocol.replace('http', 'ws') + '//' + document.location.host,
    webrtc: {
        iceServers: [
            { urls: "stun:stun.l.google.com:19302" }
        ]
    }
})
