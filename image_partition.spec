# -*- mode: python -*-

block_cipher = None


a = Analysis(['/Users/bound_to_love/EcoCensus/CurrentImplementation03092018/resources/Scripts/image_partition.py'],
             pathex=['/Users/bound_to_love/EcoCensus'],
             binaries=[],
             datas=[],
             hiddenimports=[],
             hookspath=[],
             runtime_hooks=[],
             excludes=[],
             win_no_prefer_redirects=False,
             win_private_assemblies=False,
             cipher=block_cipher)
pyz = PYZ(a.pure, a.zipped_data,
             cipher=block_cipher)
exe = EXE(pyz,
          a.scripts,
          a.binaries,
          a.zipfiles,
          a.datas,
          name='image_partition',
          debug=False,
          strip=False,
          upx=True,
          runtime_tmpdir=None,
          console=True )
