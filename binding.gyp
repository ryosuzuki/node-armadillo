{
  "targets": [
    {
      "target_name": "armadillo",
      "sources": ['src/gg.cpp',
      ],
      'cflags!': [ '-fno-exceptions' ],
      'cflags_cc!': [ '-fno-exceptions' ],
      'libraries': [
        '-llapack','-lblas', '/usr/local/opt/armadillo/lib/libarmadillo.dylib'
      ],
      'include_dirs': [
        'include', '/usr/loca/opt/armadillo/include',
        "<!(node -e \"require('nan')\")"
      ],
      "conditions" : [
        ['OS=="mac"', {
          "xcode_settings": {
            'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
            'OTHER_CPLUSPLUSFLAGS' : ['-std=c++11','-stdlib=libc++'],
            'MACOSX_DEPLOYMENT_TARGET': '10.7'
          }
        }],
        ['OS=="linux"', {
            "cflags": [ "-std=c++11" ]
        }]
      ]
    }
  ]
}
